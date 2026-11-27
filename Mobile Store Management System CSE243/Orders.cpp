#pragma once
#ifndef Orders
#include<iostream>
#include<string>
#include "Linked_List.cpp"
#include "Mobile.cpp"
using namespace std;


class Orders {
private:
	string orderId;
	LinkedList<Mobile> mobiles;
	double cost;
	int customerId;
public:
	string getOrderId() { return orderId; }
	void setOrderId(string id) { orderId = id; cout << "set successfully"; }
	LinkedList<Mobile>& getMobiles();
	void setMobiles(const LinkedList<Mobile>&);
	double getCost() { return cost; }
	void setCost(double newcost) { cost = newcost; cout << "cost set successfully"; }
	void addMobile(const Mobile&);
	//void addMobile(const Mobile& m) { mobiles.insertEnd(m); }
	bool removeMobile(string mobileId);
	double calculateCost();
};


#endif Orders // !Orders
