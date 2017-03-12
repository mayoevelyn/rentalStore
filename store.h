//-----------------------------------------------------------------------------
// Title:            Store Class
// Files:            store.h
//-----------------------------------------------------------------------------
// Store class: makes a store. Can add users, transactions, and items.
//  Includes the following functions:
//  -- add users from a file
//  -- add transactions from a file
//  -- add items to inventory from a file
//  -- retrieve item
//  -- retrieve user
//  -- display all store information
//  -- display users
//  -- display inventory
//-----------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include "hashtable.h"
#include "media.h"
#include "user.h"
#include "transaction.h"


class Store {
public:
   Store();             // constructor
   Store(const Store&); // copy constructor
   ~Store();            // destructor

   // store building functions
   void initInventory(std::ifstream&);
   void initUsers(std::ifstream&);
   void initTransactions(std::ifstream&)
   void addMedia(Media);

   // other functions
   void applyTransactions();  // applied from queue

   void display() const;      // both users and inventory
   void displayUsers() const; // users only
   void displayInventory();   // inventory only

   User* getUser(const User*&) const;     // pointer to a user
   Media* getMedia(const Media*&) const;  // pointer to a media

private:
   HashTable<User>* users;
   BST<Media>* inventory;
   queue<Transaction>* transactions;
};
#endif