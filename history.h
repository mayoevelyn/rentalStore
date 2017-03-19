//--------------------------------history.h------------------------------------
// This is a subclass of the Transaction class. It stores information for a
// history transaction and handles the transaction. This class outputs the
// transaction history of the user.
//-----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

class User;

class History : public Transaction {
public:
	virtual bool execute();
	virtual void display();
	virtual void setData(string data);

private:
	int userID;
	User* user;
};

#endif
