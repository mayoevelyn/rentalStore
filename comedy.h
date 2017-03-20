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
    // output function
    virtual void print(ostream& output) const;

    virtual void addStock(DVD* toAdd);

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
};

#endif
