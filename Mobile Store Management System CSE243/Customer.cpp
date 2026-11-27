class Customer : public User
{
	Customer() {}
    Customer(string name, string email, string password) {
        setName(name);
        setEmail(email);
        setPassword(password);
        setID("C11" + to_string(Database.getLastID(2) + 1));
    }

};
