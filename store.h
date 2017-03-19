#ifndef STORE_H
#define STORE_H

#include "transaction.h"
#include "transactionfactory.h"
#include "borrow.h"
#include "inventory.h"
#include "return.h"
#include "history.h"
#include "hashtable.h"
#include "user.h"
#include "bintree.h"
#include "dvd.h"
#include "dvdfactory.h"
#include <iostream>
#include <string>

using namespace std;

class Store {
public:
	Store();				// constructor
	Store(const Store&);	// copy constructor
	~Store();				// destructor

	// store building functions
	void buildInventory(ifstream& infile);
	void buildUsers(ifstream& infile);
	void applyTransactions(ifstream& infile);	// applied from queue

private:
	string storeName;
	HashTable<User>* users;
	BinTree<DVD>* classicInven;
	BinTree<DVD>* comedyInven;
	BinTree<DVD>* dramaInven;
	DVDFactory dvdFactory;
	TransactionFactory transFactory;
};
#endif
