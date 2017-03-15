//--------------------------------history.cpp----------------------------------
// This is a subclass of the Transaction class. It stores information for a
// history transaction and handles the transaction. This class outputs the
// transaction history of the user.
//-----------------------------------------------------------------------------

#include "history.h"

History::History() {
    customer = NULL;
}

History::~History() {
    customer = NULL;
}

bool History::execute() {
    if (customer == NULL) return false;
    customer->displayHistory();
    return true;
}

bool History::setCustomer(User* custom) {
    if (custom == NULL) return false;
    else {
        customer = custom;
        return true;
    }
}

bool History::display() {
    cout << "H " << 
}