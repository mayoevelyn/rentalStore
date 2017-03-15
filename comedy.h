//---------------------------------comedy.h------------------------------------
// Comedy class: Implements a DVD that is comedy type movie. 
//  Inherits from DVD
//  Includes the following functions:
//  -- process extra info from DVD into release year
//-----------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include <sstream>
#include <string>

#include "dvd.h"

using namespace std;

class Comedy : public DVD {
public:
    // processes extra info into release year
    void processInfo(string extraInfo);

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

private:
    // release year of the movie
    int releaseYear;
};

#endif
