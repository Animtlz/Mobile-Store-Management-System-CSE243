#include <iostream>
#include <string>
#include <cstdlib>
#include "User.cpp"
#include "Mobile.cpp"
#include "Database.cpp"
using namespace std;

User *sessionUser = nullptr;
bool isAdminSession = false;

void viewAdminMenu(Database &db);
void viewCustomerMenu(Database &db);

void signIn(Database &db)
{
    string email, password;
    cout << "\033[2J\033[1;1H";
    cout << "Please enter your email: ";
    cin >> email;
    cout << "Please enter your password: ";
    cin >> password;

    for (auto n = db.users.Head; n != nullptr; n = n->next)
        if (n->data.getEmail() == email && n->data.getPassword() == password)
        {
            sessionUser = &n->data;
            return;
        }
    sessionUser = nullptr;
    cout << "Wrong email or password.\n";
    cin.ignore();
    cin.get();
}

void registerUser(Database &db)
{
    string name, email, password, adminPasscode;
    bool makeAdmin = false;
    cout << "\033[2J\033[1;1H";
    cout << "Please enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Please enter your email: ";
    cin >> email;
    cout << "Please enter your password: ";
    cin >> password;
    cout << "Are you registering as an admin? (y/n): ";
    char adminChoice;
    cin >> adminChoice;
    if (adminChoice == 'y' || adminChoice == 'Y')
    {
        cout << "Enter admin passcode: ";
        cin >> adminPasscode;
        if (adminPasscode != "BadrByakolBatates")
        {
            cout << "Incorrect admin passcode. Registering as a customer.\n";
            cin.ignore(1000, '\n');
            cin.get(); // wait
        }
        else { makeAdmin = true; }
    }

    db.users.insertEnd(User(name, email, password, makeAdmin));
    db.saveData();
    sessionUser = &db.users.tail->data;
}

int main()
{
    Database db;
    db.loadData();
    while (true)
    {
    while (sessionUser == nullptr)
    {
        cout << "\033[2J\033[1;1H";
        cout << "Please sign in or register to continue." << endl;
        cout << "[1] Sign In" << endl;
        cout << "[2] Register" << endl;
        int choice;
        if (!(cin >> choice))
        {
            if (cin.eof()) { db.saveData(); return 0; }
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (choice == 1) signIn(db);
        else if (choice == 2) registerUser(db);
        else cout << "Invalid choice. Please try again." << endl;
    }

    isAdminSession = sessionUser->getIsAdmin();
    
    while (sessionUser != nullptr)
    {
        cout << "\033[2J\033[1;1H";
        if (isAdminSession){viewAdminMenu(db);}
        else {viewCustomerMenu(db);}
    }
    }
}

void addMobile(Database &db)
{
    cout << "\033[2J\033[1;1H";
    cout << "Please enter the following details for the new mobile:" << endl;
    string mobileName, model;
    double mobilePrice;
    int warrantyPeriod, storage, stock;
    cout << "Mobile Name: ";
    cin.ignore();
    getline(cin, mobileName);
    cout << "Model: ";
    getline(cin, model);
    cout << "Price: ";
    cin >> mobilePrice;
    cout << "Warranty Period (in months): ";
    cin >> warrantyPeriod;
    cout << "Storage (in GB): ";
    cin >> storage;
    cout << "Stock: ";
    cin >> stock;
    Mobile newMobile = Mobile(mobileName, model, mobilePrice, warrantyPeriod, storage, stock);
    db.mobiles.insertEnd(newMobile);
}

void removeMobile(Database &db)
{
    cout << "\033[2J\033[1;1H";
    db.mobiles.displayAll(true);
    cout << "\nPlease enter the Mobile ID of the mobile to remove: ";
    string mobileId;
    cin >> mobileId;
    Mobile* mobile = db.getMobileById(mobileId);
    if (mobile != nullptr)
    {
        mobile->setAvailability(false);
        cout << "Mobile removed successfully." << endl;
    }
    else
        cout << "Mobile not found." << endl;
}

void updateMobile(Database &db)
{
    cout << "\033[2J\033[1;1H";
    db.mobiles.displayAll(true);
    cout << "\nPlease enter the Mobile ID of the mobile to update: ";
    string mobileId;
    cin >> mobileId;
    Mobile* mobile = db.getMobileById(mobileId);
    if (mobile != nullptr)
    {
        cout << "Please enter the new details for the mobile:" << endl;
        string mobileName, model;
        double mobilePrice;
        int warrantyPeriod, storage, stock;
        cout << "Mobile Name: ";
        cin.ignore();
        getline(cin, mobileName);
        cout << "Model: ";
        getline(cin, model);
        cout << "Price: ";
        cin >> mobilePrice;
        cout << "Warranty Period (in months): ";
        cin >> warrantyPeriod;
        cout << "Storage (in GB): ";
        cin >> storage;
        cout << "Stock: ";
        cin >> stock;

        mobile->update(mobileName, model, mobilePrice, warrantyPeriod, storage, stock);
        cout << "Mobile updated successfully." << endl;
    }
    else
        cout << "Mobile not found." << endl;
}

void viewAllMobiles(Database &db, bool showZeroStock = false)
{
    cout << "\033[2J\033[1;1H";
    db.mobiles.displayAll(showZeroStock);
}

void viewOrders(Database &db)
{
    cout << "\033[2J\033[1;1H";
    db.orders.displayAllOrders();
}

void viewAdminMenu(Database &db)
{
    cout << "Welcome, Admin " << sessionUser->getName() << "!" << endl;
    cout << "You are now in the Admin Dashboard." << endl;
    cout << "[1] Add Mobile" << endl;
    cout << "[2] Remove Mobile" << endl;
    cout << "[3] Update Mobile" << endl;
    cout << "[4] View All Mobiles" << endl;
    cout << "[5] View Orders" << endl;
    cout << "[6] Logout" << endl;
    int choice;
    if (!(cin >> choice))
    {
        if (cin.eof()) { db.saveData(); exit(0); }
        cin.clear();
        cin.ignore(1000, '\n');
        choice = 0;
    }
    switch (choice)
    {
        case 1:
            addMobile(db);
            break;
        case 2:
            removeMobile(db);
            break;
        case 3:
            updateMobile(db);
            break;
        case 4:
            viewAllMobiles(db, true);
            break;
        case 5:
            viewOrders(db);
            break;
        case 6:
            sessionUser = nullptr;
            isAdminSession = false;
            db.saveData();
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    cin.ignore(1000, '\n');
    cin.get(); // waits for Enter
}

void placeOrder(Database &db)
{
    viewAllMobiles(db, false);
    cout << "\nPlease enter the Mobile ID of the mobile to order: ";
    string mobileId;
    cin >> mobileId;
    Mobile* mobile = db.getMobileById(mobileId);
    if (mobile == nullptr || !mobile->getAvailability())
    {
        cout << "Mobile not found." << endl;
        cin.ignore(1000, '\n');
        cin.get(); // waits for Enter
        return;
    }
    int quantity;
    cout << "Please enter the quantity to order: ";
    cin >> quantity;
    if (quantity <= 0 || quantity > mobile->getStock())
    {
        cout << "Invalid quantity." << endl;
        cin.ignore(1000, '\n');
        cin.get(); // waits for Enter
        return;
    }
    Order newOrder = Order(sessionUser->getId(), mobileId, mobile->getMobilePrice(), quantity);
    db.orders.insertEnd(newOrder);
    mobile->setStock(mobile->getStock() - quantity);
    cout << "Order " << newOrder.getOrderId() << " placed successfully." << endl;
}

void removeOrder(Database &db)
{
    cout << "\033[2J\033[1;1H";
    db.orders.displayAllOrders(sessionUser->getId());
    cout << "\nPlease enter the Order ID of the order to remove: ";
    string orderId;
    cin >> orderId;
    Order* order = db.getOrderById(orderId);
    if (order != nullptr && order->getCustomerId() == sessionUser->getId() && !order->getIsCancelled())
    {
        order->cancelOrder();
        Mobile* mobile = db.getMobileById(order->getMobileId());
        if (mobile != nullptr)
            mobile->setStock(mobile->getStock() + order->getQuantity());
        cout << "Order removed successfully." << endl;
    }
    else
        cout << "Order not found." << endl;
}


void viewCustomerMenu(Database &db)
{
    cout << "Welcome, " << sessionUser->getName() << "!" << endl;
    cout << "You are now in the Customer Dashboard." << endl;
    cout << "[1] View All Mobiles" << endl;
    cout << "[2] Place Order" << endl;
    cout << "[3] Remove Order" << endl;
    cout << "[4] Logout" << endl;
    int choice;
    if (!(cin >> choice))
    {
        if (cin.eof()) { db.saveData(); exit(0); }
        cin.clear();
        cin.ignore(1000, '\n');
        choice = 0;
    }
    switch (choice)
    {
        case 1:
            viewAllMobiles(db, false);
            break;
        case 2:
            placeOrder(db);
            break;
        case 3:
            removeOrder(db);
            break;
        case 4:
            sessionUser = nullptr;
            isAdminSession = false;
            db.saveData();
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    cin.ignore(1000, '\n');
    cin.get(); // waits for Enter
}