#pragma once
#include <string>
#include <iostream>
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
	Mobile();
	Mobile(string mobileId, string mobileName, string model, double mobilePrice,int warrantyPeriod, int storage, int stock);

	string getMobileId() const;
	void setMobileId(string mobileId);
	string getMobileName() const;
	void setMobileName(string mobileName);
	string getModel() const;
	void setModel(string model);
	double getMobilePrice() const;
	void setMobilePrice(double mobilePrice);
	int getWarrantyPeriod() const;
	void setWarrantyPeriod(int warrantyPeriod);
	int getStorage() const;
	void setStorage(int storage);
	int getStock() const;
	void setStock(int stock);

	
	bool operator==(const Mobile& other) const;

	string save() const;
	static Mobile load(const string& line);
};