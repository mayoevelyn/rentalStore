//--------------------------------history.cpp----------------------------------
// This is a subclass of the Transaction class. It stores information for a
// history transaction and handles the transaction. This class outputs the
// transaction history of the user.
//-----------------------------------------------------------------------------

#include "history.h"
#include "user.h"
#include "store.h"

void History::execute() {
    User* customer;
    bool userExists = store->getUser(customer, id);
    if (!userExists) {
        cout << "Invalid ID number: " << id;
        return;
    }
    else customer->displayHistory();
}

bool History::setCustomer() {
    User* customer;
    bool customerExists = store->getUser();
}

void History::display() {
    cout << "H " << id;
}
