//------------------------------transaction.h----------------------------------
// This class represents the transactions that can be made in a store. It
// stores the information of a transaction read from a transaction data file. 
//-----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include "hashtable.h"
#include "bintree.h"

class User;
class DVD;

using namespace std;

class Transaction {
public:	
	// virtual destructor to deal with strings
	virtual ~Transaction();
	virtual bool execute() = 0;
    virtual void display() = 0;
	virtual void setData(string data) = 0;
	
protected:
	char transType;
	char mediaType;
	HashTable<User>* users;
	BinTree<DVD>* classicInven;
	BinTree<DVD>* comedyInven;
	BinTree<DVD>* dramaInven;
};

#endif
