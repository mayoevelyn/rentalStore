//-----------------------------------------------------------------------------
// Title:            Drama class
// Files:            drama.h
//-----------------------------------------------------------------------------
// Drama class: Implements a DVD that is drama type movie.
//  Inherits from DVD
//  Includes the following functions:
//  -- process extra info from DVD into release year
//-----------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H
#include <sstream>
#include <string>
#include "dvd.h"
using namespace std;

class Drama : public DVD {
public:
	// processes extra info into release year
	void processInfo(string extraInfo);

	// comparison operator
	bool operator==(const DVD& rhs) const;
	bool operator!=(const DVD& rhs) const;
	bool operator<(const DVD& rhs) const;
	bool operator>(const DVD& rhs) const;

private:
	// release year of the movie
	int releaseYear;
};

#endif
