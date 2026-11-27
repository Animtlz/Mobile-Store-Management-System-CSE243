#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.cpp"
#include "User.cpp"
#include "Mobile.cpp"
#include "Order.cpp"
using namespace std;

class Database
{
	public:
    LinkedList<User> users;
	LinkedList<Mobile> mobiles;
    LinkedList<Order> orders;

    double getPricebyId(const string &id)
    {
        for (auto n = mobiles.Head; n; n = n->next)
            if (n->data.getMobileId() == id)
                return n->data.getMobilePrice();
        return 0.0;
    }

    Mobile* getMobileById(const string &id)
    {
        for (auto n = mobiles.Head; n; n = n->next)
            if (n->data.getMobileId() == id)
                return &n->data;
        return nullptr;
    }

    static bool blank(const string &s)
    {
        return s.find_first_not_of(" \t\r\n") == string::npos;
    }

    void saveData()
    {
        ofstream saveUsers("users.txt");
        for (auto n = users.Head; n; n = n->next)
            saveUsers << n->data.save();

        ofstream saveMobiles("mobiles.txt");
        for (auto n = mobiles.Head; n; n = n->next)
            saveMobiles << n->data.save();

        ofstream saveOrders("orders.txt");
        for (auto n = orders.Head; n; n = n->next)
            saveOrders << n->data.save();
    }

    void loadData()
    {
        users.clear();
        mobiles.clear();
        orders.clear();
        string line;
        int maxUser = 0, maxMobile = 0, maxOrder = 0;

        ifstream loadUsers("users.txt");
        while (getline(loadUsers, line))
        {
            if (blank(line)) continue;
            try
            {
                users.insertEnd(User::load(line));
                maxUser = max(maxUser, stoi(users.tail->data.getId().substr(3)));
            }
            catch (...) { cout << "Warning: skipped a corrupted line in users.txt\n"; }
        }

        ifstream loadMobiles("mobiles.txt");
        while (getline(loadMobiles, line))
        {
            if (blank(line)) continue;
            try
            {
                mobiles.insertEnd(Mobile::load(line));
                maxMobile = max(maxMobile, stoi(mobiles.tail->data.getMobileId().substr(3)));
            }
            catch (...) { cout << "Warning: skipped a corrupted line in mobiles.txt\n"; }
        }

        ifstream loadOrders("orders.txt");
        while (getline(loadOrders, line))
        {
            if (blank(line)) continue;
            try
            {
                orders.insertEnd(Order::load(line));
                maxOrder = max(maxOrder, stoi(orders.tail->data.getOrderId().substr(3)));
            }
            catch (...) { cout << "Warning: skipped a corrupted line in orders.txt\n"; }
        }

        // Loading builds objects through the constructors, which bump the ID
        // counters; reset them so new IDs continue after the highest saved one.
        Globals::latestUserID   = "C11" + to_string(maxUser);
        Globals::latestMobileID = "P11" + to_string(maxMobile);
        Globals::latestOrderID  = "O11" + to_string(maxOrder);
    }

    Order* getOrderById(const string &id)
    {
        for (auto n = orders.Head; n; n = n->next)
            if (n->data.getOrderId() == id)
                return &n->data;
        return nullptr;
    }
    
};