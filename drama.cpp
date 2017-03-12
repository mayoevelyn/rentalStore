#include "drama.h"

void Drama::processInfo(string extraInfo)
{
	// turn extraInfo into a sstream
	stringstream stream(extraInfo);

	// sets the data into release year
	stream >> releaseYear;
}

bool Drama::operator==(const DVD & rhs) const
{
	// dynamic cast parent class to child class
	const Drama* rhsCasted = dynamic_cast<const Drama*>(&rhs);
	// true if the movie's director and title is the same
	return (director == rhsCasted->director && title == rhsCasted->title);
}

bool Drama::operator!=(const DVD & rhs) const
{
	// true if lhs is not equal to rhs
	return !(*this == rhs);
}

bool Drama::operator<(const DVD & rhs) const
{
	// dynamic cast parent class to child class
	const Drama* rhsCasted = dynamic_cast<const Drama*>(&rhs);
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

bool Drama::operator>(const DVD & rhs) const
{
	// true if lhs is not equal nor smaller than rhs
	return !(*this == rhs || *this < rhs);
}
