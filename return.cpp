//---------------------------------return.h------------------------------------
// This is a subclass of the Transaction class. It stores information for a
// return transaction and handles the transaction. When an item is returned,
// the inventory of the store and user history are updated accordingly.
//-----------------------------------------------------------------------------
#include "return.h"
#include "store.h"

//---------------------------------execute-------------------------------------
// Executes a return. Three conditions are check for complete execution:
// 1) user exists 2) users have borrowed the media 3) media exists in the store
// If any are not met, then doesn't carry out transaction. That is:
//      - Removes the item from user's inventory, 
//      - Increases the DVD stock in the store by 1
//      - Adds itself to the user's history
//-----------------------------------------------------------------------------
void Return::execute(Store* store) {
    User* user = NULL;
    DVD* dvd = NULL;
    HashTable<User>* users = store->getUsers();
    DVD* dummyDVD = NULL;

    // user check
    users->retrieve(user, userID);
    if (user == NULL)
        cout << "User " << userID << " does not exist" << endl;

    // media type check
    else if (mediaType != 'D')
        cout << "Invalid media type " << mediaType << endl;

    // dvd type check
    else {
        dummyDVD = dvdFactory.makeDVD(dvdType);
        if (dummyDVD == NULL)
            cout << "Invalid movie type " << dvdType << endl;

        // check if dvd exist in inventories
        else {
            // set dummy dvd
            dummyDVD->setTransData(searchTerm);
            BinTree<DVD>* inven = NULL;
            // search the dvd from the correct tree
            switch (dvdType) {
            case 'F': 
                inven = store->getComedyInven();
                inven->retrieve(*dummyDVD, dvd);
                break;
            case 'D':
                inven = store->getDramaInven();
                inven->retrieve(*dummyDVD, dvd);
                break;
            case 'C': 
                inven = store->getClassicInven();
                inven->retrieve(*dummyDVD, dvd);
                break;
            default:
                cout << "Invalid movie type: " << dvdType << endl;
            }
        }
        // dvd doesn't exist in inventories
        if (dvd == NULL) {
            cout << "Movie does not exist: " << searchTerm << endl;
        }
    }

	// if data is good
	if (user != NULL && dvd != NULL && dummyDVD != NULL) {
		// check if user is borrowing the movie
		if (user->returnDVD(dummyDVD)) {
			// update dvd stock
			dvd->returnDVD();
			// add this transaction to history
			user->addToHistory(this);
            return;
		}
		else {
			cout << "User is not borrowing this movie" << endl;
		}
	}
    delete dummyDVD;
}

//---------------------------------display-------------------------------------
// Uses a cout to display the transaction data as the following:
// <transactiont type> <user id> <media type> <dvd type> <two search terms>
//-----------------------------------------------------------------------------
void Return::display() {
	cout << data << endl;
}

void Return::setData(string dat) {
    data = dat;
	// convert data to stream
	stringstream stream(dat);
	// set data from input
	stream >> transType >> userID >> mediaType >> dvdType;
    getline(stream, searchTerm);
}
