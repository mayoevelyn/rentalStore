//------------------------------transaction.h----------------------------------
// This class represents the transactions that can be made in a store. It
// stores the information of a transaction read from a transaction data file. 
//-----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "user.h"
#include "media.h"

class Transaction {
public:
   
   // constructor
   Transaction(char, int = -1, std::string = "", char = -1,
               char = -1, std::string = "");
   
   // destructor
   virtual ~Transaction();
   
   // accessor functions
   char getAction() const;
   int getUserID() const;
   std::string getTitle() const;
   char getMovieType() const;
   char getMediaType() const;
   std::string getMovieData() const;
   
   virtual bool executeTransaction();
   
private:
   char action;            // types of transaction: B, R, H, I
   int userID;             // user/customer ID number
   std::string title;      // title of media (DVD)
   char movieType;         // movie type: F, C, D
   char mediaType;         // media type: D (DVD)
   std::string movieData;  // extra information on media (DVD)
   
};

#endif
