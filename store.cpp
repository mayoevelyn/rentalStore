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
	Transaction* t = NULL;
	User* u = NULL;
	DVD* dummyDVD = NULL;
	DVD* dvd = NULL;
	char transType = ' ';
	int userID = 0;
	char mediaType = ' ';
	char dvdType = ' ';
	string searchTerm = "";
	string str = "";

	while(!infile.eof()) {
		getline(infile, str);
		stringstream stream(str);
		stream >> transType;
		t = transFactory.makeTransaction(transType);
		if (t == NULL) {
			cout << "Invalid transaction type" << transType << endl;
			break;
		}
		if (transType != 'I') {
			stream >> userID;
			users->retrieve(u, userID);
			if (u == NULL) {
				cout << "User " << userID << " does not exist" << endl;
				break;
			}
			if (transType != 'H') {
				stream >> mediaType;
				if (mediaType != 'D') {
					cout << "Invalid media type" << mediaType << endl;
					break;
				}
				stream >> dvdType;
				dummyDVD = dvdFactory.makeDVD(dvdType);
				if (dummyDVD == NULL) {
					cout << "Invalid movie type" << dvdType << endl;
					break;
				}
				stream >> searchTerm;
				dummyDVD->setTransData(searchTerm);
				// search the dvd from the correct tree
				switch (dvdType) {
				case 'F': comedyInven->retrieve(*dummyDVD, dvd);
					break;
				case 'D': dramaInven->retrieve(*dummyDVD, dvd);
					break;
				case 'C': classicInven->retrieve(*dummyDVD, dvd);
					break;
				default:
					cout << "Invalid movie type " << dvdType << endl;
				}
				if (dvd == NULL) {
					cout << "Movie does not exist" << dvdType << endl;
					break;
				}
			}
		}
		t->setData(u, dvd);
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


