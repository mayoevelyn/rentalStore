//-----------------------------------user.h------------------------------------
// This is the user class. A user has a unique ID number, a first name, and
// a last name. 
//-----------------------------------------------------------------------------

#include "user.h"

//--------------------------------Constructor---------------------------------
// Creates a user. Sets default valules. 
//----------------------------------------------------------------------------
User::User() {
    id = -1;
    lastname = "";
    firstname = "";
}

//----------------------------Copy Constructor--------------------------------
// Creates a user. Sets default valules. 
//----------------------------------------------------------------------------
User::User(const User& other) {
    id = other.id;
    lastname = other.lastname;
    firstname = other.firstname;
}

//---------------------------------Destructor---------------------------------
// Destruts user.
//----------------------------------------------------------------------------
User::~User() {
	// clean out borrowed
	for (auto it = borrowed.begin(); it != borrowed.end(); ++it) {
		delete (*it);
	}
	borrowed.clear();
	// clean out transaction
	for (auto it = history.begin(); it != history.end(); ++it) {
		delete (*it);
	}
	history.clear();
}

//----------------------------------setdata-----------------------------------
// Allows an input stream to set id, last name, then first name.
//----------------------------------------------------------------------------
void User::setData(string data) {
	// change param string into sstream
	stringstream stream(data);
	// set the data
	stream >> id >> lastname >> firstname;
}

//----------------------------------setID-------------------------------------
// Sets user id to parameter.
//----------------------------------------------------------------------------
void User::setID(int idToSet) {
    id = idToSet;
}

//----------------------------------getID-------------------------------------
// Returns user id.
//----------------------------------------------------------------------------
int User::getID() const {
    return id;
}

//--------------------------------getFirstName--------------------------------
// Returns first name.
//----------------------------------------------------------------------------
string User::getFirstName() const {
    return firstname;
}

//--------------------------------getLastName---------------------------------
// Returns last name.
//----------------------------------------------------------------------------
string User::getLastName() const {
    return lastname;
}

//--------------------------------addToHistory--------------------------------
// Adds transaction to history.
//----------------------------------------------------------------------------
void User::addToHistory(Transaction* transact) {
    history.push_back(transact);
}

//----------------------------removeFromInventory-----------------------------
// Adds DVD to inventory.
//----------------------------------------------------------------------------
void User::borrowDVD(DVD* toAdd) {
    borrowed.push_back(toAdd);
}

//----------------------------removeFromInventory-----------------------------
// Removes DVD from inventory. Only removes if it is actually borrowed.
//----------------------------------------------------------------------------
void User::returnDVD(DVD* toRemove) {
	vector<DVD*>::iterator iter;
	retrieveDVD(toRemove, iter);
	delete *iter;
	borrowed.erase(iter);
}

void User::addToHistory(Transaction * transact)
{
	history.push_back(transact);
}

void User::displayHistory() const {
	// prints out customer info
	cout << "History for user ";
	if (id < 10) cout << 000;
	else if (id < 100 && id >= 10) cout << 00;
	else if (id < 1000 && id >= 100) cout << 0;
	cout << id << ", " << firstname << " " << lastname << ":" << endl;
	// prints out history
	for (auto it = history.begin(); it != history.end(); ++it) {
		(*it)->display();
	}
}

bool User::retrieveDVD(DVD* toFind, vector<DVD*>::iterator found) {
	vector<DVD*>::iterator iter;
	iter = find(borrowed.begin(), borrowed.end(), toFind);
	found = iter;
	if (iter != borrowed.end())
		return true;
	else
		return false;
}

bool User::operator==(const User& rhs) const {
    if (id == rhs.id) return true;
    return false;
}

bool User::operator!=(const User& rhs) const {
    return !(*this == rhs);
}

bool User::operator>(const User& rhs) const {
    if (id > rhs.id) return true;
    return false;
}

bool User::operator<(const User& rhs) const {
    if (id < rhs.id) return true;
    return false;
}
