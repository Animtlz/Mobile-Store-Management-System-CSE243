#pragma once
#include "Linked_List.h"
#include<iostream>
using namespace std;
class DataBase {
	
	LinkedList<Customer> customers;
	LinkedList<Admin> admins;
	LinkedList<Mobile> mobiles;
public:
	static User* CurrentUser = nullptr;
	LinkedList<Customer>& getCustomers();
	LinkedList<Admin>& getAdmins();
	LinkedList<Mobile>& getMobiles();

	void saveData();
	void loadData();

	LinkedList<Mobile> searchMobileByModel(string model);
	LinkedList<Mobile> searchMobileByStorage(int storage);

};