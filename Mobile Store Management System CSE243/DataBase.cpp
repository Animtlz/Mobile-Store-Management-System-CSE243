#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Linked_List.cpp"
#include "Mobile.cpp"
using namespace std;
class DataBase
{
	const string ADMIN_PREFIX = "A11";
	const string CUSTOMER_PREFIX = "C11";
	const string MOBILE_PREFIX = "P11";

	LinkedList<Customer> customers;
	LinkedList<Admin> admins;
	LinkedList<Mobile> mobiles;

	public:
	static User *CurrentUser = nullptr;
	LinkedList<Customer> &getCustomers() { return this->customers; }
	LinkedList<Admin> &getAdmins() { return this->admins; }
	LinkedList<Mobile> &getMobiles() { return this->mobiles; }

	void saveData()
	{
		ofstream saveCustomers("customers.txt");
		auto search = this->customers.Head;
		if (saveCustomers.is_open())
		{
			while (search)
			{
				saveCustomers << search->data->save();
				search = search->next;
			}
		}
		saveCustomers.close();

		ofstream saveAdmins("admins.txt");
		search = this->admins.Head;
		if (saveAdmins.is_open())
		{
			while (search)
			{
				saveAdmins << search->data->save();
				search = search->next;
			}
		}
		saveAdmins.close();

		ofstream saveMobiles("mobiles.txt");
		search = this->mobiles.Head;
		if (saveMobiles.is_open())
		{
			while (search)
			{
				saveMobiles << search->data->save();
				search = search->next;
			}
		}
		saveMobiles.close();
	}
	void loadData()
	{
		string line;
		ifstream loadCustomers("customers.txt");
		if (loadCustomers.is_open())
		{
			while (getline(loadCustomers, line))
			{
				customers.insertEnd(Customer.load(line));
			}
			loadCustomers.close();
		}

		ifstream loadAdmins("admins.txt");
		if (loadAdmins.is_open())
		{
			while (getline(loadAdmins, line))
			{
				admins.insertEnd(Admin.load(line));
			}
			loadAdmins.close();
		}

		ifstream loadMobiles("mobiles.txt");
		if (loadMobiles.is_open())
		{
			while (getline(loadMobiles, line))
			{
				mobiles.insertEnd(Mobile.load(line));
			}
			loadMobiles.close();
		}
	}

	User searchUser(string email, string password, bool isAdmin)
	{
		auto search;
		if (isAdmin)
		{
			search = this->admins.Head;
		}
		else
		{
			search = this->customers.Head;
		}

		while (search)
		{
			if (search->data.getEmail() == email && search->data.getPassword() == password)
			{
				return search->data;
			}
			search = search->next;
		}
		return null;
	}
	bool userExists(string email)
	{
		auto search = this->admins.Head;
		while (search)
		{
			if (search->data.getEmail() == email)
			{
				return true;
			}
			search = search->next;
		}
		search = this->customers.Head;
		while (search)
		{
			if (search->data.getEmail() == email)
			{
				return true;
			}
			search = search->next;
		}
		return false;
	}

	int getLastID(int type){
		if type == 1{
			if (this->admins.isEmpty()){
				return 0;
			}
			else{
				auto search = this->admins.tail;
				string lastID = search->data.getID();
				int lastNum = stoi(lastID.substr(3));
				return lastNum;
			}
		}
		else if (type == 2){
			if (this->customers.isEmpty()){
				return 0;
			}
			else{
				auto search = this->customers.tail;
				string lastID = search->data.getID();
				int lastNum = stoi(lastID.substr(3));
				return lastNum;
			}
		}
		else if (type == 3){
			if (this->mobiles.isEmpty()){
				return 0;
			}
			else{
				auto search = this->mobiles.tail;
				string lastID = search->data.getMobileId();
				int lastNum = stoi(lastID.substr(3));
				return lastNum;
			}
		}
	}
	
	Mobile getMobileById(string id)
	{
		Mobile foundMobile = null;
		auto search = this->mobiles.Head;
		while (search)
		{
			if (search->data.getMobileId() == id)
			{
				foundMobile = search->data;
				break;
			}
			search = search->next;
		}
		return *foundMobiles;
	}
	LinkedList<Mobile> searchMobileByModel(string model)
	{
		LinkedList<Mobile> *foundMobiles = new LinkedList<Mobile>();
		auto search = this->mobiles.Head;
		while (search)
		{
			if (search->data.getModel() == model)
			{
				foundMobiles->insertEnd(search->data);
			}
			search = search->next;
		}
		return *foundMobiles;
	}
	LinkedList<Mobile> searchMobileByStorage(int storage)
	{
		LinkedList<Mobile> *foundMobiles = new LinkedList<Mobile>();
		auto search = this->mobiles.Head;
		while (search)
		{
			if (search->data.getStorage() == storage)
			{
				foundMobiles->insertEnd(search->data);
			}
			search = search->next;
		}
		return *foundMobiles;
	}
};
