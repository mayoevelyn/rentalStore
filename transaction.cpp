#include "transaction.h"

Transaction::~Transaction()
{
}

void Transaction::setData(User * user, DVD * dvd)
{
	this->user = user;
	this->dvd = dvd;
}
