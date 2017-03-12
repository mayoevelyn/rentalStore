#ifndef DVDFACTORY_H
#define DVDFACTORY_H

#include "classic.h"
#include "comedy.h"
#include "drama.h"

class DVDFactory
{
public:
	static DVD* makeDVD(const char type);
};

#endif
