#ifndef STORE_H
#define STORE_H

#include "transaction.h"
#include "transactionfactory.h"
#include "hashtable.h"
#include "user.h"
#include "bintree.h"
#include "media.h"
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
	void buildInventory(ifstream&);
	void buildUsers(ifstream&);
	void addMedia(Media*);

	// other functions
	void applyTransactions(ifstream& infile);	// applied from queue

	void display() const;		// both users and inventory
	void displayUsers() const;	// users only
	void displayInventory();	// inventory only

	bool getUser(User*& toSet, int key);		// pointer to a user
	Media* getMedia(const Media*&) const;	// pointer to a media

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
