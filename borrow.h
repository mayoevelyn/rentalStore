//---------------------------------borrow.h------------------------------------
// This is a subclass of the Transaction class. It stores information for a
// borrow transaction and handles the transaction. When an item is
// borrowed, the inventory of the store and user history are updated
// accordingly.
//-----------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H

#include <sstream>
#include "transaction.h"
#include "dvdfactory.h"
#include "user.h"

class DVD;

class Borrow : public Transaction {
public:
	virtual bool execute();
	virtual void display();
	virtual void setData(string data);

private:
	int userID;
	char dvdType;
	string searchTerm;
	User* user;
	DVD* dvd;
	DVDFactory dvdFactory;
};

#endif
