//------------------------------transaction.h----------------------------------
// This class represents the transactions that can be made in a store. It
// stores the information of a transaction read from a transaction data file. 
//-----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "user.h"
#include "media.h"
#include "hashtable.h"
#include "bintree.h"
#include <string>
using namespace std;

class Transaction
{
public:
	// constructor
	Transaction();
	
	// destructor
	virtual ~Transaction();
	
	void setData(string transData);
	virtual bool execute();
	
private:
	string transData;
	HashTable<User>* users;

};

#endif
