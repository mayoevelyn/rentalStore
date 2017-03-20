//--------------------------------history.cpp----------------------------------
// This is a subclass of the Transaction class. It stores information for a
// history transaction and handles the transaction. This class outputs the
// transaction history of the user.
//-----------------------------------------------------------------------------

#include "history.h"
#include "user.h"
#include "store.h"

//---------------------------------execute-------------------------------------
// Takes in a store. If the store has the user with the given ID, then it
// displays the user's transaction history before adding itself.
// If not, does not execute and prints an error message.
//-----------------------------------------------------------------------------
bool History::execute(Store* store) {
    HashTable<User>* customers = store->getUsers();
    User* user = NULL;
	bool userExists = customers->retrieve(user, userID);

    // do nothing if user isn't found, display error message
	if (!userExists) {
		cout << "User " << userID << " does not exist" << endl;
		cout << endl;
		return false;
	}
    
    // if user exists, display history and add to user history
	else {
		user->displayHistory();
        user->addToHistory(this);
		cout << endl;
        return true;
	}
}

//---------------------------------display-------------------------------------
// Displays transaction type and user id of the transaction.
//-----------------------------------------------------------------------------
void History::display() {
    cout << data << endl;
}

//---------------------------------setData-------------------------------------
// Takes in a string and sets transaction type H and user ID. Assumes data
// passed in is valid for a history transaction.
//-----------------------------------------------------------------------------
void History::setData(string dat) {
    data = dat;
    stringstream stream(dat);
    stream >> transType >> userID;
}
