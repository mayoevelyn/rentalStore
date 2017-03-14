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

void Store::buildUsers(ifstream& infile) {
	User* ptr;

	for (;;) {
		if (infile.eof) break;	// stop reading if end of file
		ptr = new User;
		ptr->setData(infile);
		bool success = users->insert(ptr);
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
		t = transFactory.makeTransaction(transType);
		if (t) {
			t->setData(transData, users*, );
		}
	}
}

void Store::addMedia(Media* toAdd) {

}

void Store::display() const {

}
void Store::displayUsers() const; // users only
void Store::displayInventory();   // inventory only

User* Store::getUser(const User*&) const;
Media* Store::getMedia(const Media*&) const;
