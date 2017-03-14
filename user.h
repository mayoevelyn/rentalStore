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

	// get functions
	string getID();
	string getFirstName();
	string getLastName();

	// changing history
	void addToHistory(Transaction);

	// display
	void displayHistory();
	void displayBorrowed();

private:
	int id;                    // 4 digit ID
	string lastname;              // last name
	string firstname;             // first name
	vector<Media> borrowed;
	vector<Transaction> history;
};


#endif