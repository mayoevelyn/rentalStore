//------------------------------inventory.h------------------------------------
// This is a subclass of the Transaction class. It stores information for a
// an inventory transaction and handles the transaction. This class outputs
// the inventory of the store.
//-----------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"

class Store {
    void displayInventory();
};

class Inventory : public Transaction {
public:
    virtual void execute();       // displays store's inventory
    virtual void display();
};
#endif