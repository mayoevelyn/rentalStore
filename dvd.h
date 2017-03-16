//-----------------------------------------------------------------------------
// Title:            DVD class
// Files:            dvd.h
//-----------------------------------------------------------------------------
// DVD class: A DVD type of media. Inherits from media.
//-----------------------------------------------------------------------------

#ifndef DVD_H
#define DVD_H

#include <string>
#include <iostream>
using namespace std;

class DVD {
public:
	// virtual destructor to deal with strings
	virtual ~DVD();

	// display function
	virtual void display() const = 0;

    // getters for director, title, stock, and type
    virtual char getDvdType() const = 0;
    virtual int getStock() const = 0;
    virtual string getDirector() const = 0;
    virtual string getTitle() const = 0;

	// operator overloads
	virtual bool operator==(const DVD& rhs) const = 0;
	virtual bool operator!=(const DVD& rhs) const = 0;
	virtual bool operator<(const DVD& rhs) const = 0;
	virtual bool operator>(const DVD& rhs) const = 0;

    // borrow and return
    virtual bool borrowing() = 0;
    virtual bool returning() = 0;

protected:
	char dvdType;		// char indicating DVD type
	int stock;			// number of DVDs available for borrowing
	string director;	// director of the DVD
	string title;		// title of the DVD
};
#endif

