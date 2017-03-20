//------------------------------inventory.cpp----------------------------------
// This is a subclass of the Transaction class. It stores information for a
// an inventory transaction and handles the transaction. This class outputs
// the inventory of the store.
//-----------------------------------------------------------------------------

#include "inventory.h"
#include "store.h"
bool Inventory::execute(Store* store) {
    BinTree<DVD>* printptr;
    // prints comedies, then classics, then dramas
	cout << endl;
	cout << "Store inventory (Comedy, Dramas, then Classics):" << endl;
    printptr = store->getComedyInven();
    printptr->displayTree();
    printptr = store->getClassicInven();
    printptr->displayTree();
    printptr = store->getDramaInven();
    printptr->displayTree();
	cout << endl;
    return true;
}

void Inventory::display() {
	cout << data << endl;
}

void Inventory::setData(string dat) {
    data = dat;
    transType = dat[0];
}
