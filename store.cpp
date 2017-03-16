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
		// extracts the first char for dvdType
		getline(infile, str, ',');
		dvdType = str[0];

		// use factory to create appropriate DVD type
		ptr = dvdFactory.makeDVD(dvdType);

		// get the rest of the line to pass into DVD setData
		getline(infile, str);

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
}

void Store::buildUsers(ifstream& infile) {
	User* ptr;
	for (;;) {
		if (infile.eof) break;	// stop reading if end of file
		ptr = new User;
		ptr->setData(infile);
		bool success = users->insert(ptr, ptr->getID);
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

void Store::displayInventory() {
    comedyInven->displayTree();
    dramaInven->displayTree();
    classicInven->displayTree();
}

bool Store::getUser(User*& customer, int key) {
    bool retrieved = (users->retrieve(customer, key));
    return retrieved;
}

bool Store::getDVD(char mediaType, const DVD& toGet, DVD*& toSet) {
    if (mediaType != 'D') return false;
    char dvdType = toGet.getDvdType;
    bool retrieved;
    switch (dvdType) {
    case 'F': retrieved = comedyInven->retrieve(toGet, toSet);
        break;
    case 'D': retrieved = dramaInven->retrieve(toGet, toSet);
        break;
    case 'C': retrieved = classicInven->retrieve(toGet, toSet);
        break;
    default:
        cout << "Invalid movie type" << endl;
        return false;
    }
    return retrieved;
}


