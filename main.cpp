//---------------------------------main.cpp------------------------------------
// This is a driver class for the Store class. It creates the a Store object
// by passing in 3 parameters: user data, commands or transaction data, and
// movie data. This class then applies all the transactions of the store.
//-----------------------------------------------------------------------------

#include "store.h"

int main() {
	// creates the Store object by passing user, movie, and transaction files
	Store store;
	ifstream infile("data4movies.txt");
	store.buildInventory(infile);
}
