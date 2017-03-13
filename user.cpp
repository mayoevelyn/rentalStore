#include "user.h"


User::User() {
   id = "";
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

void User::setID(string newID) {
   id = newID;
}

void User::setFirstName(string newFirstName) {
   firstname = newFirstName;
}

void User::setLastName(string newLastName) {
   lastname = newLastName;
}

   // get functions
string User::getID() {
   return id;
}
  
string User::getFirstName() {
   return firstname;
}

string User::getLastName() {
   return lastname;
}

void User::addToHistory(Transaction transact) {
   history.push_back(transact);
}


void User::displayHistory() {

}

void User::displayBorrowed() {
   cout << "Currenty borrowed media for " << id << ":" << endl;
   for (int i = 0; i < borrowed->size; i++)
      cout << *borrowed[i];
}
}

