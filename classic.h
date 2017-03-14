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
#include <sstream>
#include <string>
#include "dvd.h"
using namespace std;

class Classic : public DVD {
public:
	// processes extra info into release year
	void processInfo();

	// display
	virtual void display();

	// operator overloads
	virtual bool operator==(const DVD& rhs) const;
	virtual bool operator!=(const DVD& rhs) const;
	virtual bool operator<(const DVD& rhs) const;
	virtual bool operator>(const DVD& rhs) const;

private:
	string majorActor;  // the movie's major actor
	int releaseMonth;   // release month of the movie
	int releaseYear;    // release year of the movie
};

#endif
