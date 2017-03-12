#include "classic.h"

void Classic::processInfo()
{
	// turn extraInfo into a sstream
	stringstream stream(extraInfo);

	// process the stream into containers and variables
	string firstName, lastName;
	stream >> firstName >> lastName >> releaseMonth >> releaseYear;

	// set major actor's name
	majorActor = firstName + " " + lastName;
}

bool Classic::operator==(const DVD & rhs) const
{
	// dynamic cast parent class to child class
	const Classic* rhsCasted = dynamic_cast<const Classic*>(&rhs);
	// true if the movie's director and title is the same
	return (director == rhsCasted->director && title == rhsCasted->title);
}

bool Classic::operator!=(const DVD & rhs) const
{
	// true if lhs is not equal to rhs
	return !(*this == rhs);
}

bool Classic::operator<(const DVD & rhs) const
{
	// dynamic cast parent class to child class
	const Classic* rhsCasted = dynamic_cast<const Classic*>(&rhs);
	// check with year
	if (releaseYear < rhsCasted->releaseYear)
		return true;
	// if same year, check with month
	if (releaseYear == rhsCasted->releaseYear)
		if (releaseMonth < rhsCasted->releaseMonth)
			return true;
	// if same month, check with major actor
	if (releaseMonth == rhsCasted->releaseMonth)
		if(majorActor < rhsCasted->majorActor)
			return true;
	// else, then false
	return false;
}

bool Classic::operator>(const DVD & rhs) const
{
	// true if lhs is not equal nor smaller than rhs
	return !(*this == rhs || *this < rhs);
}
