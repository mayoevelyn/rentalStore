//------------------------------inventory.cpp----------------------------------
// This is a subclass of the Transaction class. It stores information for a
// an inventory transaction and handles the transaction. This class outputs
// the inventory of the store.
//-----------------------------------------------------------------------------

#include "inventory.h"
#include "store.h"

bool Inventory::execute() {
	comedyInven->displayTree();
	dramaInven->displayTree();
	comedyInven->displayTree();
	return true;
}

void Inventory::display() {
	cout << transType << endl;
}

void Inventory::setData(string data) {
}
