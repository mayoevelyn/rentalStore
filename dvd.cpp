//-----------------------------------dvd.cpp-----------------------------------
// DVD class: A DVD type class. Has a DVD type, stock, director, and title.
// Functions are to be inherited from derived classes.
//-----------------------------------------------------------------------------

#include "dvd.h"

DVD::~DVD() {
}

//-------------------------------borrowing-------------------------------------
// Returns false if stock is 0. Returns true and decreases stock by 1 if not.
//-----------------------------------------------------------------------------
bool DVD::borrowDVD() {
	if (stock == 0) return false;
	stock--;
	return true;
}

//-------------------------------returning-------------------------------------
// Returns true and increases stock by 1.
//-----------------------------------------------------------------------------
bool DVD::returnDVD() {
	stock++;
	return true;
}

ostream& operator<<(ostream& output, const DVD& toPrint) {
    toPrint.print(output);
    return output;
}