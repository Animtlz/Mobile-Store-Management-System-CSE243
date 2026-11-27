#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Globals.cpp"
using namespace std;

class Mobile
{
private:
    string mobileId;
    string mobileName;
    string model;
    double mobilePrice = 0.0;
    int warrantyPeriod = 0;
    int storage = 0;
    int stock = 0;
    bool isAvailable = true;

public:
    Mobile(string mobileName, string model, double mobilePrice, int warrantyPeriod, int storage, int stock)
    {
        this->mobileName = mobileName;
        this->model = model;
        this->mobilePrice = mobilePrice;
        this->warrantyPeriod = warrantyPeriod;
        this->storage = storage;
        this->stock = stock;
        Globals::latestMobileID = "P11" + to_string(stoi(Globals::latestMobileID.substr(3)) + 1);
        this->mobileId = Globals::latestMobileID;
    };

    bool getAvailability() { return this->isAvailable; }
    string getMobileId() { return this->mobileId; } 
    // string getMobileName() { return this->mobileName; }
    // string getModel() { return this->model; }
    double getMobilePrice() { return this->mobilePrice; }
    // int getWarrantyPeriod() { return this->warrantyPeriod; }
    // int getStorage() { return this->storage; }
    int getStock() { return this->stock; } 
    void setAvailability(bool availability) { this->isAvailable = availability; }
    void setStock(int stock) { this->stock = stock; }
    void update(string mobileName, string model, double mobilePrice, int warrantyPeriod, int storage, int stock)
    {
        this->mobileName = mobileName;
        this->model = model;
        this->mobilePrice = mobilePrice;
        this->warrantyPeriod = warrantyPeriod;
        this->storage = storage;
        this->stock = stock;
    }

    string save() {
        return mobileId + "\t" + mobileName + "\t" + model + "\t" + to_string(mobilePrice) + "\t" + to_string(warrantyPeriod)
            + "\t" + to_string(storage) + "\t" + to_string(stock) + "\t" + (isAvailable ? "1" : "0") + "\n";
    }

    static Mobile load(const string &line) {
        vector<string> f = Globals::split(line);
        Mobile m(f.at(1), f.at(2), stod(f.at(3)), stoi(f.at(4)), stoi(f.at(5)), stoi(f.at(6)));
        m.mobileId = f.at(0);
        m.isAvailable = (f.at(7) == "1");
        return m;
    }

    void display(bool showZeroStock = false) {
        if (!isAvailable) return;
        if (showZeroStock || stock > 0) {
            cout << "│ " << left << setw(9) << mobileId << " │ " << setw(22) << mobileName << " │ " << setw(12) << model
                << " │ $" << setw(9) << fixed << setprecision(2) << mobilePrice << " │ " << setw(9) << warrantyPeriod
                << " │ " << setw(9) << storage << " │ " << setw(9) << stock << " │" << endl;
        }
    };

    void displayHeader() {
        cout << "┌───────────┬────────────────────────┬──────────────┬────────────┬───────────┬───────────┬───────────┐" << endl;
        cout << "│ Mobile ID │ Mobile Name            │ Model        │ Price      │ Warranty  │ Storage   │ Stock     │" << endl;
        cout << "├───────────┼────────────────────────┼──────────────┼────────────┼───────────┼───────────┼───────────┤" << endl;
    };

    void displayFooter() {
        cout << "└───────────┴────────────────────────┴──────────────┴────────────┴───────────┴───────────┴───────────┘" << endl;
    };
};
