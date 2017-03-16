//-----------------------------------------------------------------------------
// Title:            Classic class
// Files:            classic.h
//-----------------------------------------------------------------------------
// Classic class: Implements a DVD that is classic type movie. 
//  Inherits from DVD
//  Includes the following functions:
//  -- process extra info from DVD into major actor, release month & year
//-----------------------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H

#include "dvd.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Classic : public DVD {
public:
	// sets the data for the DVD
	virtual void setData(string data);

	// display
	virtual void display();

	// operator overloads
	virtual bool operator==(const DVD& rhs) const;
	virtual bool operator!=(const DVD& rhs) const;
	virtual bool operator<(const DVD& rhs) const;
	virtual bool operator>(const DVD& rhs) const;

    // borrow and return
    virtual bool borrowing();
    virtual bool returning();


private:
	string majorActor;  // the movie's major actor
	int releaseMonth;   // release month of the movie
	int releaseYear;    // release year of the movie
};

#endif
