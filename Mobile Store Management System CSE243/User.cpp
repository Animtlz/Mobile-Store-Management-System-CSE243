class User {
	private:
		string id;
		string name;
		string email;
		string password;

	public:
		string getID() { return id; }
		string getName() { return name; }
		string getEmail() { return email; }
		string getPassword() { return password; }
        void setID(string newId) { id = newId; }
        void setName(string newName) { name = newName; }
        void setEmail(string newEmail) { email = newEmail; }
        void setPassword(string newPassword) { password = newPassword; }
        void showDashboard() {
            cout << "This user is neither an admin nor a customer. You shouldn't be seeing this." << endl;
            cin >> int stayAwake;
        }
};
