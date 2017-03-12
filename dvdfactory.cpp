#include "dvdfactory.h"

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
