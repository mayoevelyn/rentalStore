#include "classic.h"

void Classic::setData(ifstream& infile) {
	// container to be reused for holding data
	string str;

	// set stock
	getline(infile, str, ',');
	stock = stoi(str);
	// set director
	getline(infile, str, ',');
	director = str;
	// set title
	getline(infile, str, ',');
	title = str;

	// process the stream into containers and release date
	string firstName, lastName;
	infile >> firstName >> lastName >> releaseMonth >> releaseYear;

	// set major actor's name
	majorActor = firstName + " " + lastName;
}

bool Classic::operator==(const DVD & rhs) const {
	// dynamic cast parent class to child class
	const Classic* rhsCasted = dynamic_cast<const Classic*>(&rhs);
	// true if the movie's director and title is the same
	return (director == rhsCasted->director && title == rhsCasted->title);
}

bool Classic::operator!=(const DVD & rhs) const {
	// true if lhs is not equal to rhs
	return !(*this == rhs);
}

bool Classic::operator<(const DVD & rhs) const {
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

bool Classic::operator>(const DVD & rhs) const {
	// true if lhs is not equal nor smaller than rhs
	return !(*this == rhs || *this < rhs);
}

//-------------------------------borrowing-------------------------------------
// Returns false if stock is 0. Returns true and decreases stock by 1 if not.
//-----------------------------------------------------------------------------
bool Classic::borrowing() {
    if (stock == 0) return false;
    stock--;
    return true;
}

//-------------------------------returning-------------------------------------
// Returns true and increases stock by 1.
//-----------------------------------------------------------------------------
bool Classic::returning() {
    stock++;
    return true;
}
