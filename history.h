//--------------------------------history.h------------------------------------
// This is a subclass of the Transaction class. It stores information for a
// history transaction and handles the transaction. This class outputs the
// transaction history of the user.
//-----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

class Store;

class History : public Transaction {
public:
    History();
    ~History();
    virtual bool execute();          // displays user's transaction history
    bool setCustomer(Store*);
    virtual void display();
};

#endif 