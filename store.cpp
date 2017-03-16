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
			cout << "Invalid movie type " << dvdType << endl;
		}
	}
	ptr = NULL;
}

void Store::buildUsers(ifstream& infile) {
	User* ptr;
	string str;

	// while there is still data
	while (!infile.eof) {
		// create new user
		ptr = new User;
		// read one line
		getline(infile, str);
		// pass the line into setData
		ptr->setData(str);
		// try to insert user
		bool success = users->insert(ptr, ptr->getID);
		// if insert unsuccessful, delete the ptr
		if (!success) delete ptr;
	}
}

void Store::applyTransactions(ifstream& infile) {
	Transaction* t;
	char transType;
	string str;

	while(!infile.eof()) {
		getline(infile, str);
		transType = str[0];
		t = transFactory.makeTransaction(transType);
		if (t) {
			t->setData(str);
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


