//----------------------------------store.h------------------------------------
// Store class: This is the class for a store of DVD itmes. It has three kinds
// of DVDs, classic, drama, and comedy. It also has a list of customers/users
// who may borrow and return these DVDs. 
//-----------------------------------------------------------------------------
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
	~Store();				// destructor

	// store building functions
	void buildInventory(ifstream& infile);
	void buildUsers(ifstream& infile);
	void applyTransactions(ifstream& infile);	// applied from queue

    // getters
    HashTable<User>* getUsers() const;
    BinTree<DVD>* getComedyInven() const;
    BinTree<DVD>* getClassicInven() const;
    BinTree<DVD>* getDramaInven() const;
    string getStorename() const;

private:
	string storeName;               // store name
	HashTable<User>* users;         // all users, sorted by ID
	BinTree<DVD>* classicInven;     // classic movies
	BinTree<DVD>* comedyInven;      // comedy movies
	BinTree<DVD>* dramaInven;       // drama movies
	DVDFactory dvdFactory;          // makes dvds
	TransactionFactory transFactory;// makes transactions
};
#endif
