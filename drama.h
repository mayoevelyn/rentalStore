//--------------------------------drama.h--------------------------------------
// Drama class: Implements a DVD that is drama type movie.
//  Inherits from DVD
//  Sorted by direector, then title.
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
    // output function
    virtual void print(ostream& output) const;

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
};

#endif
