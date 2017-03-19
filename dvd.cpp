//-----------------------------------------------------------------------------
// Title:            DVD class
// Files:            dvd.h
//-----------------------------------------------------------------------------
// DVD class: A DVD type of media. Inherits from media.
//-----------------------------------------------------------------------------

#include "dvd.h"

DVD::~DVD()
{
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
