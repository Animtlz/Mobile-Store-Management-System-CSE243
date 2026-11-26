#include "Mobile.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Mobile::Mobile() {
	this->mobilePrice = 0;
	this->warrantyPeriod = 0;
	this->storage = 0;
	this->stock = 0;
}

Mobile::Mobile(string mobileId, string mobileName, string model, double mobilePrice,
	int warrantyPeriod, int storage, int stock) {
	this->mobileId = mobileId;
	this->mobileName = mobileName;
	this->model = model;
	this->mobilePrice = mobilePrice;
	this->warrantyPeriod = warrantyPeriod;
	this->storage = storage;
	this->stock = stock;
}


string Mobile::getMobileId() const { return this->mobileId; }
void Mobile::setMobileId(string mobileId) { this->mobileId = mobileId; }
string Mobile::getMobileName() const { return this->mobileName; }
void Mobile::setMobileName(string mobileName) { this->mobileName = mobileName; }
string Mobile::getModel() const { return this->model; }
void Mobile::setModel(string model) { this->model = model; }
double Mobile::getMobilePrice() const { return this->mobilePrice; }
void Mobile::setMobilePrice(double mobilePrice) { this->mobilePrice = mobilePrice; }
int Mobile::getWarrantyPeriod() const { return this->warrantyPeriod; }
void Mobile::setWarrantyPeriod(int warrantyPeriod) { this->warrantyPeriod = warrantyPeriod; }
int Mobile::getStorage() const { return this->storage; }
void Mobile::setStorage(int storage) { this->storage = storage; }
int Mobile::getStock() const { return this->stock; }
void Mobile::setStock(int stock) { this->stock = stock; }



bool Mobile::operator==(const Mobile& other) const {
	return this->mobileId == other.mobileId;
}


//el bombaa
string Mobile::save() const {
	return mobileId + "|" + mobileName + "|" + model + "|" +
		to_string(mobilePrice) + "|" + to_string(warrantyPeriod) + "|" +
		to_string(storage) + "|" + to_string(stock) + "\n";
}//database yetsaraf

Mobile Mobile::load(const string& line) {
	Mobile m;
	stringstream ss(line);
	string price, warranty, storage, stock;

	getline(ss, m.mobileId, '|');
	getline(ss, m.mobileName, '|');
	getline(ss, m.model, '|');

	getline(ss, price, '|');
	getline(ss, warranty, '|');
	getline(ss, storage, '|');
	getline(ss, stock, '|');

	//changing string to data types needed to make phone object

	m.mobilePrice = stod(price);
	m.warrantyPeriod = stoi(warranty);
	m.storage = stoi(storage);
	m.stock = stoi(stock);

	return m;
}