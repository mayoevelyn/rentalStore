//-----------------------------------user.h------------------------------------
// This is the user class. A user has a unique ID number, a first name, and
// a last name. 
//-----------------------------------------------------------------------------

#include "user.h"

////--------------------------------Constructor---------------------------------
//// Creates a user. Sets default valules. 
////----------------------------------------------------------------------------
//User::User() {
//    id = -1;
//    lastname = "";
//    firstname = "";
//}

//---------------------------------Destructor---------------------------------
// Destructs user
//----------------------------------------------------------------------------
User::~User() {
    // clean out borrowed
    for (DVD* dvd : borrowed) {
        delete dvd;
    }
    borrowed.clear();
    // clean out transaction
    for (Transaction* trans : history) {
        delete trans;
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
bool User::borrowDVD(DVD* toAdd) {
    borrowed.push_back(toAdd);
    return true;
}

//----------------------------removeFromInventory-----------------------------
// Removes DVD from inventory. Only removes if it is actually borrowed.
//----------------------------------------------------------------------------
bool User::returnDVD(DVD* toRemove) {
    vector<DVD*>::iterator iter;
    if (retrieveDVD(toRemove, iter)) {
        delete *iter;
        borrowed.erase(iter);
        return true;
    }
    else
       return false;
}

//-------------------------------displayHistory-------------------------------
// Displays list of transaction history.
//----------------------------------------------------------------------------
void User::displayHistory() const {
    // prints out customer info
    cout << "History for user ";
    if (id < 10) cout << 000;
    else if (id < 100 && id >= 10) cout << 00;
    else if (id < 1000 && id >= 100) cout << 0;
    cout << id << ", " << firstname << " " << lastname << ":" << endl;
    // prints out history
    for (Transaction* trans : history) {
        trans->display();
    }
}

//----------------------------------retrieve----------------------------------
// Returns true if DVD passed in is found.
//----------------------------------------------------------------------------
bool User::retrieveDVD(DVD* toFind, vector<DVD*>::iterator found) {
    vector<DVD*>::iterator iter;
    iter = find(borrowed.begin(), borrowed.end(), toFind);
    found = iter;
    if (iter != borrowed.end())
        return true;
    else
        return false;
}

//---------------------------------operator==---------------------------------
// True if id is equal to rhs' id.
//----------------------------------------------------------------------------
bool User::operator==(const User& rhs) const {
    if (id == rhs.id) return true;
    return false;
}

//---------------------------------operato!=---------------------------------
// True if id is not equal to rhs' id.
//----------------------------------------------------------------------------
bool User::operator!=(const User& rhs) const {
    return !(*this == rhs);
}

//---------------------------------operator>----------------------------------
// True if id is greater than rhs' id.
//----------------------------------------------------------------------------
bool User::operator>(const User& rhs) const {
    return (id > rhs.id);
}

//---------------------------------operator<----------------------------------
// True if id is less than rhs' id.
//----------------------------------------------------------------------------
bool User::operator<(const User& rhs) const {
    return (id < rhs.id);
}