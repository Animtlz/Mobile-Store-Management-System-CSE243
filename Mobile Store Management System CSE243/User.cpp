#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Globals.cpp"
using namespace std;

class User
{
    private:
        string id;
        string name;
        string email;
        string password;
        bool isAdmin;

    public:
        User();
        User(string name, string email, string password, bool isAdmin=false){
            this->name = name;
            this->email = email;
            this->password = password;
            this->isAdmin = isAdmin;
            string prefix = isAdmin ? "A11" : "C11";
            Globals::latestUserID = prefix + to_string(stoi(Globals::latestUserID.substr(3)) + 1);
            this->id = Globals::latestUserID;
        }

        // No need to use setters since user information can't be changed later.
        string getId() { return this->id; }
        string getName() { return this->name; }
        string getEmail() { return this->email; }
        string getPassword() { return this->password; }
        bool getIsAdmin() { return this->isAdmin; }

        string save() {
            return id + "\t" + name + "\t" + email + "\t" + password + "\t" + (isAdmin ? "1" : "0") + "\n";
        }

        static User load(const string &line) {
            vector<string> f = Globals::split(line);
            User u(f.at(1), f.at(2), f.at(3), f.at(4) == "1");
            u.id = f.at(0);
            return u;
        }

        void display(bool unused) {
            if (isAdmin) return; 
            cout << "│ " << left << setw(13) << id << " │ " << setw(82) << name << " │" << endl;
        }

        void displayHeader() {
            cout << "┌───────────────┬────────────────────────────────────────────────────────────────────────────────────┐" << endl;
            cout << "│ Customer ID   │ Customer Name                                                                      │" << endl;
            cout << "├───────────────┼────────────────────────────────────────────────────────────────────────────────────┤" << endl;
        }

        void displayFooter() {
            cout << "└───────────────┴────────────────────────────────────────────────────────────────────────────────────┘" << endl;
        }
};