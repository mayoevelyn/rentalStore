#ifndef MEDIAFACTORY_H
#define MEDIAFACTORY_H

#include "dvd.h"
class MediaFactory
{
public:
	static Media* makeMedia(const char type);
};
#endif
