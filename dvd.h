//-----------------------------------dvd.h-------------------------------------
// DVD class: A DVD type class. Has a DVD type, stock, director, and title.
// Functions are to be inherited from derived classes.
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

    virtual void print(ostream& output) const = 0;

    friend ostream& operator<<(ostream& output, const DVD& toPrint);

	// set data function
	virtual void setData(string data) = 0;
	// set trans data function
	virtual void setTransData(string data) = 0;
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
    bool borrowDVD();
    bool returnDVD();

protected:
	char dvdType = '0';		// char indicating DVD type
	int stock = '0';		// number of DVDs available for borrowing
	string director = "";	// director of the DVD
	string title = "";		// title of the DVD
    int releaseYear = -1;   // release year of movie
};
#endif

