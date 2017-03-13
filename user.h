#ifndef _USER_H
#define _USER_H

#include <fstream>   // file reading
#include <iostream>  // file reading
#include <vector>      // list of borrowed items
#include <string>    // any strings used

#include "media.h"         // media object
#include "transaction.h"   // transaction object

using namespace std;

class User {
public:
   User();              // constructor
   User(const User&);   // copy constructor
   ~User();             // destructor

   void setData(ifstream&);
   void setID(string);
   void setFirstName(string);
   void setLastname(string);

   // get functions
   string getID();
   string getFirstName();
   string getLastName();

   // adding and removing media by quantity
   void removeFromInventory(Media, int);
   void addToInventory(Media, int); 

   // changing history
   void addToHistory(Transaction);

   // display
   void displayHistory();
   void displayBorrowed();

private:
   string id;                    // 4 digit ID
   string lastname;              // last name
   string firstname;             // first name
   vector<Media> borrowed;
   vector<Transaction> history;
};


#endif