//-------------------------transactionFactory.cpp------------------------------
// Factory class for the Transaction ojbect. Can create a borrow, return, 
// history, or inventory Transaction.
//-----------------------------------------------------------------------------
#include "transactionfactory.h"

//------------------------------makeTransaction--------------------------------
// Takes in a character. Returns borrow if type == 'B', return if type == 'R', 
// history if type == 'H', or inventory if type == 'I'. Returns NULL otherwise.
//-----------------------------------------------------------------------------
Transaction* TransactionFactory::makeTransaction(char action) {
	// container for a Transaction object
	Transaction* trans = NULL;

	// switch case to create appropriate Transaction based on type
	switch (action) {
	case 'B':
		trans = new Borrow();
		break;
	case 'R':
		trans = new Return();
		break;
	case 'I':
		trans = new Inventory();
		break;
	case 'H':
        trans = new History();
		break;
	default:
		break;
	}

	// return the assigned Transaction pointer, or NULL if invalid case
	return trans;
}
