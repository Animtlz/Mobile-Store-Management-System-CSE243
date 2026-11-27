#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Mobile {
private:
	string mobileId;
	string mobileName;
	string model;
	double mobilePrice;
	int warrantyPeriod;   
	int storage;          
	int stock;            

public:
	Mobile() {
		setMobilePrice(0.0);
		setWarrantyPeriod(0);
		setStorage(0);
		setStock(0);
	}
	Mobile(string mobileName, string model, double mobilePrice,
		int warrantyPeriod, int storage, int stock) {
		setMobileId("P11" + to_string(Database.getLastID(1) + 1));
		setMobileName(mobileName);
		setModel(model);
		setMobilePrice(mobilePrice);
		setWarrantyPeriod(warrantyPeriod);
		setStorage(storage);
		setStock(stock);
	}

	string getMobileId() const { return this->mobileId; }
	void setMobileId(string mobileId) { this->mobileId = mobileId; }
	string getMobileName() const { return this->mobileName; }
	void setMobileName(string mobileName) { this->mobileName = mobileName; }
	string getModel() const { return this->model; }
	void setModel(string model) { this->model = model; }
	double getMobilePrice() const { return this->mobilePrice; }
	void setMobilePrice(double mobilePrice) { this->mobilePrice = mobilePrice; }
	int getWarrantyPeriod() const { return this->warrantyPeriod; }
	void setWarrantyPeriod(int warrantyPeriod) { this->warrantyPeriod = warrantyPeriod; }
	int getStorage() const { return this->storage; }
	void setStorage(int storage) { this->storage = storage; }
	int getStock() const { return this->stock; }
	void setStock(int stock) { this->stock = stock; }

	
	bool operator==(const Mobile& other) const {
		return this->mobileId == other.mobileId;
	}

	//el bombaa
	string save() const {
		return mobileId + "|" + mobileName + "|" + model + "|" +
			to_string(mobilePrice) + "|" + to_string(warrantyPeriod) + "|" +
			to_string(storage) + "|" + to_string(stock) + "\n";
	}//database yetsaraf
	
	static Mobile load(const string& line) {
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
};
