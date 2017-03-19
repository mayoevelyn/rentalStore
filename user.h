//-----------------------------------user.h------------------------------------
// This is the user class. A user has a unique ID number, a first name, and
// a last name. 
//-----------------------------------------------------------------------------

#ifndef USER_H
#define USER_H

#include <fstream>		// file reading
#include <iostream>		// file reading
#include <sstream>		// file reading
#include <vector>		// list of borrowed items
#include <string>		// any strings used
#include <algorithm>	// for finding
#include "transaction.h"
#include "dvd.h"

using namespace std;

class User {
public:
   //User();              // constructor
   ~User();             // destructor

   void setData(string data);

   // get functions
   int getID() const;
   string getFirstName() const;
   string getLastName() const;

   // sets ID for a dummy user
   void setID(int idToSet);

   // adding and removing DVD by quantity
   bool borrowDVD(DVD* toAdd);
   bool returnDVD(DVD* toRemove);

   // changing history
   void addToHistory(Transaction* transact);

   // display
   void displayHistory() const;

   // if has DVD or not, helper for remove
   bool retrieveDVD(DVD* toFind, vector<DVD*>::iterator found);

   // boolean operators
   bool operator==(const User& rhs) const;
   bool operator!=(const User& rhs) const;
   bool operator>(const User& rhs) const;
   bool operator<(const User& rhs) const;

private:
   int id;						// user id
   string lastname;				// last name
   string firstname;			// first name
   vector<DVD*> borrowed;		// all borrowed materials
   vector<Transaction*> history;	// all transactions of the user
};

#endif
