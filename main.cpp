//---------------------------------main.cpp------------------------------------
// This is a driver class for the Store class. It creates the a Store object
// by passing in 3 parameters: user data, commands or transaction data, and
// movie data. This class then applies all the transactions of the store.
//-----------------------------------------------------------------------------

#include "store.h"

int main() {
	// creates the Store object by passing user, movie, and transaction files
	Store store;

	ifstream infile1("data4movies.txt");
	ifstream infile2("data4customers.txt");
	ifstream infile3("data4commands.txt");

	store.buildInventory(infile1);
	store.buildUsers(infile2);
	store.applyTransactions(infile3);

	return 1;
}
