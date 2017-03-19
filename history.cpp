//--------------------------------history.cpp----------------------------------
// This is a subclass of the Transaction class. It stores information for a
// history transaction and handles the transaction. This class outputs the
// transaction history of the user.
//-----------------------------------------------------------------------------

#include "history.h"
#include "user.h"
#include "store.h"

bool History::execute() {
	users->retrieve(user, userID);
	if (user == NULL) {
		cout << "User " << userID << " does not exist" << endl;
		return false;
	}
	else {
		user->displayHistory();
		return true;
	}
}

void History::display() {
	cout << transType << userID << endl;
}

void History::setData(string data) {
	userID = stoi(data);
}
