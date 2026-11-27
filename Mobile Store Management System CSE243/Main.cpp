#include <iostream>
#include <string>
#include "DataBase.cpp"
#include "User.cpp"
using namespace std;

// ---------- Entry point ----------
User currentUser = null;
int main()
{
    DataBase db;
    db.loadData(); 

    while currentUser == null {
        int userSelection;
        cout << "Welcome to the Mobile Store Management System!\n";
        cout << "[0] Sign In";
        cout << "[1] Register";
        cin >> userSelection;

        switch (userSelection) {
            case 0:
                signIn();
                break;
            case 1:
                registerUser();
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }
    }

    currentUser.showDashboard();
    
    db.saveData();       
    cout << "Goodbye!\n";
    return 0;
}


bool signIn(){
    string email, password;
    cout << "Please enter your email: ";
    cin >> email;
    cout << "Please enter your password: ";
    cin >> password;

    currentUser = Database.searchUser(email, password);
    return currentUser != null;
}

bool registerUser() {
    string name, email, password, adminPasscode;
    char isAdminChar;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your email: ";
    cin >> email;
    cout << "Please enter your password: ";
    cin >> password;
    cout << "Are you registering as an admin? (y/n): ";
    cin >> isAdminChar;
    if (isAdminChar == 'y') {
        cout << "Please enter your admin passcode: ";
        cin >> adminPasscode;
        if (adminPasscode != "badrByakolBatates") {
            cout << "Incorrect admin passcode. Registration failed.";
            return false;
        }
    }

    if (Database.userExists(email)) {
        cout << "User already exists with this email.";
        return false;
    }

    if (isAdminChar == 'y') {
        Database.getAdmins().insertEnd(Admin(name, email, password));
    } else {
        Database.getCustomers().insertEnd(Customer(name, email, password));
    }
    cout << "Registration successful!";
    return true;
}
//testing branches remove after this dw :)