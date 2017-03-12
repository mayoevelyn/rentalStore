//-----------------------------------------------------------------------------
// Title:            DVD class
// Files:            dvd.h
//-----------------------------------------------------------------------------
// DVD class: A DVD type of media. Inherits from media.
//-----------------------------------------------------------------------------

#include "dvd.h"

DVD::DVD(char dvdType, int stock, string director, string title, string extraInfo)
{
	this->dvdType = dvdType;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->extraInfo = extraInfo;
}

DVD::~DVD()
{
}
