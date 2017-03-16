//---------------------------------comedy.h------------------------------------
// Comedy class: Implements a DVD that is comedy type movie. 
//  Inherits from DVD
//  Includes the following functions:
//  -- process extra info from DVD into release year
//-----------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "dvd.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Comedy : public DVD {
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
    void setTitle(string newTitle);
    void setReleaseYear(int newReleaseYear);

    // display
    virtual void display() const;

    // comparison operators
    virtual bool operator==(const DVD& rhs) const;
    virtual bool operator!=(const DVD& rhs) const;
    virtual bool operator<(const DVD& rhs) const;
    virtual bool operator>(const DVD& rhs) const;

    // borrow and return
    virtual bool borrowing();
    virtual bool returning();

private:
    // release year of the movie
    int releaseYear;
};

#endif
