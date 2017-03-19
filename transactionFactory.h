//-------------------------transactionFactory.h--------------------------------
// Factory class of the Transaction class that has the factory method.
//-----------------------------------------------------------------------------

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "transaction.h"
#include "borrow.h"
#include "history.h"
#include "return.h"
#include "inventory.h"

class TransactionFactory {
public:
   // factory method to create instances of different subclasses of
   // Transaction object
   static Transaction* makeTransaction(char action);
};

#endif
