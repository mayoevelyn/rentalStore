//--------------------------------history.h------------------------------------
// This is a subclass of the Transaction class. It stores information for a
// history transaction and handles the transaction. This class outputs the
// transaction history of the user.
//-----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

class History : public Transaction {
public:
   bool executeTransaction();          // displays user's transaction history
};

#endif 
