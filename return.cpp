#include "return.h"

bool Return::execute() {
	// if data is good
	if (user != NULL && dvd != NULL) {
		// check if user is borrowing the movie
		if (user->returnDVD(dvd)) {
			// update dvd stock
			dvd->returnDVD();
			// add this transaction to history
			user->addToHistory(this);
			return true;
		}
		else {
			cout << "User is not borrowing this movie" << endl;
			return false;
		}
	}
	else return false;
}

void Return::display() {
	cout << transType << userID << mediaType << dvdType << searchTerm << endl;
}

void Return::setData(string data) {
	// convert data to stream
	stringstream stream(data);
	// set data from input
	stream >> userID >> mediaType >> dvdType >> searchTerm;

	// filters input data
	// user check
	users->retrieve(user, userID);
	if (user == NULL)
		cout << "User " << userID << " does not exist" << endl;

	// media type check
	else if (mediaType != 'D')
		cout << "Invalid media type " << mediaType << endl;

	// dvd type check
	else {
		DVD* dummyDVD = dvdFactory.makeDVD(dvdType);
		if (dummyDVD == NULL)
			cout << "Invalid movie type " << dvdType << endl;

		// check if dvd exist in inventories
		else {
			// set dummy dvd
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
		}
		// delete dummy dvd
		delete dummyDVD;
		// dvd doesn't exist in inventories
		if (dvd == NULL) {
			cout << "Movie does not exist" << dvdType << endl;
		}
	}
}
