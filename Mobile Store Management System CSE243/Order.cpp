#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Globals.cpp"
using namespace std;

class Order
{
    string orderId;
    string customerId;
    string mobileId;
    int quantity;
    double Price;
    bool isCancelled = false;

public:
    Order(string customerId, string mobileId, double unitPrice, int quantity)
    {
        this->customerId = customerId;
        this->mobileId = mobileId;
        this->quantity = quantity;
        this->Price = unitPrice * quantity;
        Globals::latestOrderID = "O11" + to_string(stoi(Globals::latestOrderID.substr(3)) + 1);
        this->orderId = Globals::latestOrderID;
    }

    string save() {
        return orderId + "\t" + customerId + "\t" + mobileId + "\t" + to_string(quantity) + "\t" + to_string(Price)
            + "\t" + (isCancelled ? "1" : "0") + "\n";
    }

    static Order load(const string &line) {
        vector<string> f = Globals::split(line);
        Order o(f.at(1), f.at(2), 0.0, stoi(f.at(3)));
        o.orderId = f.at(0);
        o.Price = stod(f.at(4));
        o.isCancelled = (f.at(5) == "1");
        return o;
    }

    void cancelOrder() { this->isCancelled = true; }
    string getOrderId() { return this->orderId; }
    string getCustomerId() { return this->customerId; }
    string getMobileId() { return this->mobileId; }
    int getQuantity() { return this->quantity; }
    bool getIsCancelled() { return this->isCancelled; }

    void displayOrder(string customerId = "") {
        if (isCancelled) return;
        if (customerId != "" && this->customerId != customerId) return;
        cout << "│ " << left << setw(13) << orderId
            << " │ " << setw(13) << this->customerId
            << " │ " << setw(13) << mobileId
            << " │ " << setw(10) << quantity
            << " │ " << setw(37) << fixed << setprecision(2) << Price << " │" << endl;
    }

    static void displayHeader() {
        cout << "┌───────────────┬───────────────┬───────────────┬────────────┬───────────────────────────────────────┐" << endl;
        cout << "│ Order ID      │ Customer ID   │ Mobile ID     │ Quantity   │ Total Price                           │" << endl;
        cout << "├───────────────┼───────────────┼───────────────┼────────────┼───────────────────────────────────────┤" << endl;
    }

    static void displayFooter() {
        cout << "└───────────────┴───────────────┴───────────────┴────────────┴───────────────────────────────────────┘" << endl;
    }

};