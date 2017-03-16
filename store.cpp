#include "store.h"

// Constructor for the store.
Store::Store() {

}

// Creates a store based on the given store.
Store::Store(const Store& rhs) {

}

Store::~Store() {
	
}

void Store::buildInventory(ifstream& infile) {
	DVD* ptr;
	char dvdType;
	string str;

	// while there is still data
	while(!infile.eof()) {
		// reads one line
		getline(infile, str);

		// extracts the first char for dvdType
		dvdType = str[0];

		// use factory to create appropriate DVD type
		ptr = dvdFactory.makeDVD(dvdType);

		// set the DVD data
		ptr->setData(str);
		// sort the dvd into the correct tree
		switch (dvdType) {
		case 'F': comedyInven->insert(ptr);
			break;
		case 'D': dramaInven->insert(ptr);
			break;
		case 'C': classicInven->insert(ptr);
			break;
		default:
			cout << "Invalid movie type" << endl;
		}
	}
	ptr = NULL;
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

	while(!infile.eof()) {
		infile >> transType;
		getline(infile, transData);
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
void Store::displayInventory();   // inventory only


bool Store::getUser(User*& customer, int key) {
    bool retrieved = (users->retrieve(customer, key));
    return retrieved;
}

Media* Store::getMedia(const Media*&) const;

