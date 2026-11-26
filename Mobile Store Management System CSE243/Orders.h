#pragma once
#ifndef Orders
#define Orders
#include<iostream>
#include<string>
#include "Linked_List.h"
#include "Mobile.h"
using namespace std;


class orders {
	string orderId;
	LinkedList<Mobile> mobiles;
	double cost;
	int customerId;
	orders() {}
	string getOrderId();
	void setOrderId(string Id);
	LinkedList<Mobile>& getMobiles();
	void setMobiles(const LinkedList<Mobile>&);
	double getCost();
	void setCost(double cost);
	void addMobile(const Mobile&);
	bool removeMobile(string mobileId);
	double calculateCost();
};


#endif Orders // !Orders
