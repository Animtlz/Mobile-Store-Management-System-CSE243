#pragma once
#include "DataBase.h"
#include <fstream>
#include<iostream>
#include <string>
using namespace std;

 LinkedList<Customer>& DataBase::getCustomers() {return this->customers;}
 LinkedList<Admin>& DataBase::getAdmins() { return this->admins; }
 LinkedList<Mobile>& DataBase::getMobiles() { return this->mobiles; }

 void DataBase::saveData(){
	 ofstream saveCustomers("customers.txt");
	 auto search = this->customers.Head;
	 if (saveCustomers.is_open()) {
		 while (search) {
			 saveCustomers << search->data->save();
			 search = search->next;
		 }
	 }
	 saveCustomers.close();

	 ofstream saveAdmins("admins.txt");
	 search = this->admins.Head;
	 if (saveAdmins.is_open()) {
		 while (search) {
			 saveAdmins << search->data->save();
			 search = search->next;
		 }
	 }
	 saveAdmins.close();

	 ofstream saveMobiles("mobiles.txt");
	 search = this->mobiles.Head;
	 if (saveMobiles.is_open()) {
		 while (search) {
			 saveMobiles << search->data->save();
			 search = search->next;
		 }
	 }
	 saveMobiles.close();
 }
 void DataBase::loadData(){
	 string line;
	 ifstream loadCustomers("customers.txt");
	 if (loadCustomers.is_open()) {
		 while (getline(loadCustomers, line)) {
			 customers.insertEnd(Customer.load(line));
		 }
		 loadCustomers.close();
	 }
	 
	 ifstream loadAdmins("admins.txt");
	 if (loadAdmins.is_open()) {
		 while (getline(loadAdmins, line)) {
			 admins.insertEnd(Admin.load(line));
		 }
		 loadAdmins.close();
	 }
	 
	 ifstream loadMobiles("mobiles.txt");
	 if (loadMobiles.is_open()) {
		 while (getline(loadMobiles, line)) {
			 mobiles.insertEnd(Mobile.load(line));
		 }
		 loadMobiles.close();
	 }
}


LinkedList<Mobile> DataBase::searchMobileByModel(string model){
	LinkedList<Mobile>* foundMobiles = new LinkedList<Mobile>();
	auto search = this->mobiles.Head;
	while (search) {
		if (search->data->model == model) {
			foundMobiles->insertEnd(search->data);
		}
		search = search->next;
	}
}
 LinkedList<Mobile> DataBase::searchMobileByStorage(int storage){
	 LinkedList<Mobile>* foundMobiles = new LinkedList<Mobile>();
	 auto search = this->mobiles.Head;
	 while (search) {
		 if (search->data->storage == storage) {
			 foundMobiles->insertEnd(search->data);
		 }
		 search = search->next;
	 }
}
