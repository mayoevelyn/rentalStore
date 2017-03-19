//-------------------------------dvdFactory.cpp--------------------------------
// Factory class for the DVD ojbect. Can create a classic, comedy, or drama 
// DVD.
//-----------------------------------------------------------------------------
#include "dvdfactory.h"

//----------------------------------makeDVD------------------------------------
// Takes in a character. Returns classic if type == 'C', comedy if type == 'F' 
// or drama if type == 'D'. Returns NULL if char is any other.
//-----------------------------------------------------------------------------
DVD* DVDFactory::makeDVD(const char type)
{
	DVD* dvd = NULL;

	switch (type)
	{
	case 'F':
		dvd = new Comedy();
		break;
	case 'D':
		dvd = new Drama();
		break;
	case 'C':
		dvd = new Classic();
		break;
	default:
		break;
	}
	
	return dvd;
}
