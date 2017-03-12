//-----------------------------------------------------------------------------
// Title:            User class
// Files:            user.h
//-----------------------------------------------------------------------------
// User class: A user has an id number, a first name, last name, history, and
// items borrowed.
//  Includes the following functions:
//  -- get first name
//  -- get last name
//  -- get ID number
//  -- display history
//  -- display borrowed items
//  -- add media to borrowed
//  -- remove media from borrowed
//  -- return if something is borrowed
//-----------------------------------------------------------------------------

#ifndef _USER_H
#define _USER_H

#include <fstream>   // file reading
#include <iostream>  // file reading
#include <list>      // list of borrowed items
#include <queue>     // history queue
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

   // get functions
   int getID();
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
   
   // has item or not?
   bool hasMedia(const Media*&) const;

private:
   int id;                       // 4 digit ID
   string lastname;              // last name
   string firstname;             // first name
   list<Media>* borrowed;
   queue<Transaction>* history;
};


#endif