//-----------------------------------user.h------------------------------------
// This is the user class. A user has a unique ID number, a first name, and
// a last name. 
//-----------------------------------------------------------------------------

#ifndef _USER_H
#define _USER_H

#include <fstream>   // file reading
#include <iostream>  // file reading
#include <vector>      // list of borrowed items
#include <string>    // any strings used

#include "dvd.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"

using namespace std;

class User {
public:
   User();              // constructor
   User(const User&);   // copy constructor
   ~User();             // destructor

   void setData(ifstream&);

   // get functions
   int getID() const;
   string getFirstName() const;
   string getLastName() const;

   // sets ID for a dummy user
   void setID(int idToSet);

   // adding and removing DVD by quantity
   void removeFromInventory(DVD* toRemvove);
   void addToInventory(DVD* toAdd); 

   // changing history
   void addToHistory(Transaction transact);

   // display
   void displayHistory() const;

   // if has DVD or not
   bool hasDVD(DVD* toFind) const;

   // boolean operators
   bool operator==(const User& rhs) const;
   bool operator!=(const User& rhs) const;
   bool operator>(const User& rhs) const;
   bool operator<(const User& rhs) const;

private:
   int id;                      // user id
   string lastname;             // last name
   string firstname;            // first name
   vector<DVD> borrowed;        // all borrowed materials
   vector<Transaction> history; // all transactions of the user
};

#endif
