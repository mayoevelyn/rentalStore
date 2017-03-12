//------------------------------inventory.h------------------------------------
// This is a subclass of the Transaction class. It stores information for a
// an inventory transaction and handles the transaction. This class outputs
// the inventory of the store.
//-----------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory : public Transaction {
public:
   bool executeTransaction();       // displays store's inventory
};

#endif
