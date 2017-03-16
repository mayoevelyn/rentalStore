#include "transactionfactory.h"

Transaction* TransactionFactory::makeTransaction(char action) {
	// container for a Transaction object
	Transaction* trans = NULL;

	// switch case to create appropriate Transaction based on type
	switch (action) {
	case 'B':
		trans = new Borrow;
		break;
	case 'R':
		trans = new Return;
		break;
	case 'I':
		trans = new Inventory;
		break;
	case 'H':
		trans = new History;
		break;
	default:
		break;
	}

	// return the assigned Transaction pointer, or NULL if invalid case
	return trans;
}
