#include "store.h"

// Constructor for the store.
Store::Store() {
	inventory = NULL;
	users = NULL;
}

// Creates a store based on the given store.
Store::Store(const Store& rhs) {

}

Store::~Store() {
	
}

void Store::buildInventory(ifstream& mediaInfile) {
	Media* ptr;
	char mediaType;
	for (;;) {
		if (mediaInfile.eof) break;	// stop reading if end of file
		mediaInfile >> mediaType;
		
		bool success = inventory->insert(ptr);
		if (!success) delete ptr;

	}
}

void Store::buildUsers(std::ifstream&) {
	User* ptr;
	char mediaType;
	for (;;) {
		if (mediaInfile.eof) break;	// stop reading if end of file

		bool success = inventory->insert(ptr);
		if (!success) delete ptr;

	}
}

void Store::applyTransactions(ifstream& infile) {
	char transType;
	string transData;
	Transaction* t;

	infile >> transType;
	getline(infile, transData);

	while(!infile.eof()) {
		t = TransactionFactory.makeTransaction(transType);
		if (t) {
			t->setData(transData);
		}
		myList.append(p);
	}
}

void Store::addMedia(Media* toAdd) {

}

void Store::applyTransactions()
{
}

void Store::display() const {

}
void Store::displayUsers() const; // users only
void Store::displayInventory();   // inventory only

User* Store::getUser(const User*&) const;
Media* Store::getMedia(const Media*&) const;

