//------------------------------inventory.cpp----------------------------------
// This is a subclass of the Transaction class. It stores information for a
// an inventory transaction and handles the transaction. This class outputs
// the inventory of the store.
//-----------------------------------------------------------------------------

#include "inventory.h"
#include "store.h"

void Inventory::execute() {
    store->displayInventory();
}

void Inventory::display() {
    cout << "I";
}
