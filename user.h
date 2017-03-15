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

#include "media.h"
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

   // adding and removing media by quantity
   void removeFromInventory(Media* toRemvove);
   void addToInventory(Media* toAdd); 

   // changing history
   void addToHistory(Transaction transact);

   // display
   void displayHistory() const;

   // if has media or not
   bool hasMedia(Media* toFind) const;

   // boolean operators
   bool operator==(const User& rhs) const;
   bool operator>(const User& rhs) const;
   bool operator<(const User& rhs) const;

private:
   int id;                    // 4 digit ID
   string lastname;              // last name
   string firstname;             // first name
   vector<Media> borrowed;
   vector<Transaction> history;
};
#endif
