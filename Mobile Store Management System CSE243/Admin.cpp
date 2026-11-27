class Admin : public User
{
	Admin() {}
    Admin(string name, string email, string password) {
        setName(name);
        setEmail(email);
        setPassword(password);
        setID("A11" + to_string(Database.getLastID(1) + 1));
    }
    void showDashboard() {
        printDashboard();
        cout << "Please select an option: ";
        int selection;
        cin >> selection;
        while (selection != 6) {
            switch (selection) {
                case 1:
                    addMobile();
                    break;
                case 2:
                    removeMobile();
                    break;
                case 3:
                    updateMobile();
                    break;
                case 4:
                    viewAllMobiles();
                    break;
                case 5:
                    /* code for viewing orders */
                    break;
                default:
                    cout << "Invalid selection. Please try again." << endl;
            }
            printDashboard();
            cout << "Please select an option: ";
            cin >> selection;
        }
        return;
        
    }

    void printDashboard() {
        cout << "Welcome, Admin " << getName() << "!" << endl;
        cout << "You are now in the Admin Dashboard." << endl;
        cout << "[1] Add Mobile" << endl;
        cout << "[2] Remove Mobile" << endl;
        cout << "[3] Update Mobile" << endl;
        cout << "[4] View All Mobiles" << endl;
        cout << "[5] View Orders" << endl;
        cout << "[6] Logout" << endl;
    }

    void addMobile() {
        string mobileName, model;
        double mobilePrice;
        int warrantyPeriod, storage, stock;

        cout << "Enter mobile name: ";
        cin >> mobileName;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter price: ";
        cin >> mobilePrice;
        cout << "Enter warranty period (in months): ";
        cin >> warrantyPeriod;
        cout << "Enter storage (in GB): ";
        cin >> storage;
        cout << "Enter stock quantity: ";
        cin >> stock;

        Mobile newMobile(mobileName, model, mobilePrice, warrantyPeriod, storage, stock);
        Database.getMobiles().insertEnd(newMobile);
    }

    void removeMobile() {
        string mobileId;
        cout << "Enter the mobile ID to remove: ";
        cin >> mobileId;

        Mobile mobile = Database.getMobileById(mobileId);
        if (mobile.getMobileById() == null) {
            cout << "Mobile not found." << endl;
            return;
        }

        Database.getMobiles().deleteNode(mobile);
        cout << "Mobile removed successfully." << endl;
    }

    void updateMobile() {
        string mobileId;
        cout << "Enter the mobile ID to remove: ";
        cin >> mobileId;

        Mobile mobile = Database.getMobileById(mobileId);
        if (mobile.getMobileById() == null) {
            cout << "Mobile not found." << endl;
            return;
        }

        cout << "Enter mobile name: ";
        cin >> mobileName;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter price: ";
        cin >> mobilePrice;
        cout << "Enter warranty period (in months): ";
        cin >> warrantyPeriod;
        cout << "Enter storage (in GB): ";
        cin >> storage;
        cout << "Enter stock quantity: ";
        cin >> stock;
        mobile.setMobileName(mobileName);
        mobile.setModel(model);
        mobile.setPrice(mobilePrice);
        mobile.setWarrantyPeriod(warrantyPeriod);
        mobile.setStorage(storage);
        mobile.setStock(stock);
    }

    void viewAllMobiles() {
        LinkedList<Mobile> &mobiles = Database.getMobiles();
        mobiles.displayAll();
    }
};
