//-----------------------------------------------------------------------------
// Title:            DVD class
// Files:            dvd.h
//-----------------------------------------------------------------------------
// DVD class: A DVD type of media. Inherits from media.
//-----------------------------------------------------------------------------

#ifndef DVD_H
#define DVD_H

#include "media.h"
#include <string>
using namespace std;

class DVD : public Media {
public:
	// constructor
	DVD(char dvdType = ' ', int stock = 0, string director = "", string title = "",  
	string extraInfo = "");
	// virtual destructor to deal with strings
	virtual ~DVD();

	// operator overloads
	virtual bool operator==(const DVD& rhs) const = 0;
	virtual bool operator!=(const DVD& rhs) const = 0;
	virtual bool operator<(const DVD& rhs) const = 0;
	virtual bool operator>(const DVD& rhs) const = 0;

protected:
	char dvdType;		// char indicating DVD type
	int stock;			// number of DVDs available for borrowing
	string director;	// director of the DVD
	string title;		// title of the DVD
	string extraInfo;	// trailing information from an DVD input line
};

#endif
