//-----------------------------------drama.h-----------------------------------
// Drama class: Implements a DVD that is drama type movie.
//  Inherits from DVD
//  Includes the following functions:
//  -- process extra info from DVD into release year
//-----------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H

#include "dvd.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Drama : public DVD {
public:
	// sets the data for the DVD
	virtual void setData(string data);
	// set trans data function
	virtual void setTransData(string data);

    // getters
    virtual char getDvdType() const;
    virtual int getStock() const;
    virtual string getDirector() const;
    virtual string getTitle() const;
    int getReleaseYear() const;

    // setters
    void setDirector(string newDirector);
    void setTitle(string newTitle);

    // display
    virtual void display() const;

    // comparison operators
	bool operator==(const DVD& rhs) const;
	bool operator!=(const DVD& rhs) const;
	bool operator<(const DVD& rhs) const;
	bool operator>(const DVD& rhs) const;

private:
	// release year of the movie
	int releaseYear;
};

#endif
