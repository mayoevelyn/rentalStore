//----------------------------------classic.h----------------------------------
// Classic class: Implements a DVD that is classic type movie. 
//  Inherits from DVD
//  Sorted by release date, then by major actor.
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
    int getReleaseMonth() const;

    // setters
    void setReleaseYear(int newReleaseYear);
    void setReleaseMonth(int newReleaseMonth);
    void setMajorActor(string newMajorActor);

	// display
	virtual void display() const;

	// operator overloads
	virtual bool operator==(const DVD& rhs) const;
	virtual bool operator!=(const DVD& rhs) const;
	virtual bool operator<(const DVD& rhs) const;
	virtual bool operator>(const DVD& rhs) const;

private:
	string majorActor = "";  // the movie's major actor
	int releaseMonth = -1;   // release month of the movie
};

#endif
