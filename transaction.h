//------------------------------transaction.h----------------------------------
// This class represents the transactions that can be made in a store. It
// stores the information of a transaction read from a transaction data file. 
//-----------------------------------------------------------------------------

#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include <string>
#include <iostream>

class Store;
class User;

using namespace std;

class Transaction {
public:	
	// destructor
	virtual ~Transaction();
	virtual void execute() = 0;
    virtual void display() = 0;
	
protected:
	char transactType;
	Store* store;
};

#endif
