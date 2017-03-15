//-----------------------------------user.h------------------------------------
// This is the user class. A user has a unique ID number, a first name, and
// a last name. 
//-----------------------------------------------------------------------------

#include "user.h"

User::User() {
    id = -1;
    lastname = "";
    firstname = "";
}

User::User(const User& other) {
    id = other.id;
    lastname = other.lastname;
    firstname = other.firstname;
}

User::~User() {
}

void User::setData(ifstream& input) {
    input >> id >> lastname >> firstname;
}


void User::setID(int idToSet) {
    id = idToSet;
}

// get functions
int User::getID() const {
    return id;
}

string User::getFirstName() const {
    return firstname;
}

string User::getLastName() const {
    return lastname;
}

void User::addToHistory(Transaction transact) {
    history.push_back(transact);
}

void User::removeFromInventory(Media* toRemove) {
    if (hasMedia(toRemove)) {
        history.erase(*toRemove);
    }
}

void User::addToInventory(Media* toAdd) {
    if (!hasMedia(toAdd)) {
        history.push_back(*toAdd);
    }
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

bool User::hasMedia(Media* toFind) const {
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

bool User::operator>(const User& rhs) const {
    if (id > rhs.id) return true;
    return false;
}

bool User::operator<(const User& rhs) const {
    if (id < rhs.id) return true;
    return false;
}
