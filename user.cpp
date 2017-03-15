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
}

//----------------------------------setdata-----------------------------------
// Allows an input stream to set id, last name, then first name.
//----------------------------------------------------------------------------
void User::setData(ifstream& input) {
    input >> id >> lastname >> firstname;
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
void User::addToHistory(Transaction transact) {
    history.push_back(transact);
}

//----------------------------removeFromInventory-----------------------------
// Removes DVD from inventory. Only removes if it is actually borrowed.
//----------------------------------------------------------------------------
void User::removeFromInventory(DVD* toRemove) {
    if (hasDVD(toRemove)) {
        borrowed.erase(*toRemove);
    }
}

//----------------------------removeFromInventory-----------------------------
// Adds DVD to inventory.
//----------------------------------------------------------------------------
void User::addToInventory(DVD* toAdd) {
    borrowed.push_back(*toAdd);
}

void User::displayHistory() const {
    cout << "History for User ";
    if (id < 10) cout << 000;
    else if (id < 100 && id >= 10) cout << 00;
    else if (id < 1000 && id >= 100) cout << 0;
    cout << id << ", " << lastname << " " << firstname << ":" << endl;
    for (int i = 0; i < history.size; i++) {
        history[i].display();
    }
}

bool User::hasDVD(DVD* toFind) const {
    bool contains = false;
    for (int i = 0; i < borrowed.size; i++) {
        if (borrowed[i] == *toFind) contains = true;
    }
    return contains;
}

bool User::operator==(const User& rhs) const {
    if (id == rhs.id) return true;
    return false;
}

bool User::operator!=(const User& rhs) const {
    return (*this == rhs) == false;
}

bool User::operator>(const User& rhs) const {
    if (id > rhs.id) return true;
    return false;
}

bool User::operator<(const User& rhs) const {
    if (id < rhs.id) return true;
    return false;
}
