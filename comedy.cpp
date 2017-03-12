#include "comedy.h"

void Comedy::processInfo(string extraInfo)
{
	// turn extraInfo into a sstream
	stringstream stream(extraInfo);

	// sets the data into release year
	stream >> releaseYear;
}

bool Comedy::operator==(const DVD & rhs) const
{
	// dynamic cast parent class to child class
	const Comedy* rhsCasted = dynamic_cast<const Comedy*>(&rhs);
	// true if the movie's director and title is the same
	return (director == rhsCasted->director && title == rhsCasted->title);
}

bool Comedy::operator!=(const DVD & rhs) const
{
	// true if lhs is not equal to rhs
	return !(*this == rhs);
}

bool Comedy::operator<(const DVD & rhs) const
{
	// dynamic cast parent class to child class
	const Comedy* rhsCasted = dynamic_cast<const Comedy*>(&rhs);
	// check with director
	if (director < rhsCasted->director)
		return true;
	// if same director, check with title
	if (director == rhsCasted->director)
		if (title < rhsCasted->title)
			return true;
	// else, then false
	return false;
}

bool Comedy::operator>(const DVD & rhs) const
{
	// true if lhs is not equal nor smaller than rhs
	return !(*this == rhs || *this < rhs);
}
