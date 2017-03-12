//---------------------------------return.h------------------------------------
// This is a subclass of the Transaction class. It stores information for a
// return transaction and handles the transaction. When an item is returned,
// the inventory of the store and user history are updated accordingly.
//-----------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

class Return : public Transaction {
public:
   bool executeTransaction();       // updates all info
   
private:
   void updateInventory() const;    // updates store inventory
   void updateBorrowedList() const; // updates user's borrowed list
   void updateUserHistory() const;  // updates user's transaction history
};

#endif
