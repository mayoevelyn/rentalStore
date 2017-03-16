//---------------------------------comedy.h------------------------------------
// Comedy class: Implements a DVD that is comedy type movie. 
//  Inherits from DVD
//  Includes the following functions:
//  -- process extra info from DVD into release year
//-----------------------------------------------------------------------------

#include "comedy.h"

//-------------------------------processInfo-----------------------------------
// Takes in a string and sets it as the release year.
//-----------------------------------------------------------------------------
void Comedy::setData(ifstream& infile) {
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
	// sets the release year
	infile >> releaseYear;
}

//----------------------------------getDvdType---------------------------------
// Returns the DVD type.
//-----------------------------------------------------------------------------
char Comedy::getDvdType() const {
    return dvdType;
}

//----------------------------------getStock-----------------------------------
// Returns the stock amount.
//-----------------------------------------------------------------------------
int Comedy::getStock() const {
    return stock;
}

//----------------------------------getDirector--------------------------------
// Returns the director.
//-----------------------------------------------------------------------------
string Comedy::getDirector() const {
    return director;
}

//----------------------------------getTitle-----------------------------------
// Returns the title.
//-----------------------------------------------------------------------------
string Comedy::getTitle() const {
    return title;
}

//-------------------------------getReleaseYear--------------------------------
// Returns the releaseYear.
//-----------------------------------------------------------------------------
int Comedy::getReleaseYear() const {
    return releaseYear;
}

//----------------------------------setTitle-----------------------------------
// Set title to the passed in title.
//-----------------------------------------------------------------------------
void Comedy::setTitle(string newTitle) {
    title = newTitle;
}

//----------------------------------setDirector--------------------------------
// Set director to the passed in director.
//-----------------------------------------------------------------------------
void Comedy::setReleaseYear(int newReleaseYear) {
    releaseYear = newReleaseYear;
}

//----------------------------------display------------------------------------
// Displays the following, each separated by commas:
// Dvd type, stock, director, title, release year
//-----------------------------------------------------------------------------
void Comedy::display() const {
    cout << dvdType << ", " << stock << ", " << director << ", " << title
        << ", " << releaseYear;
}

//-------------------------------operator==------------------------------------
// Returns true if rhs has the same title and release year.
//-----------------------------------------------------------------------------
bool Comedy::operator==(const DVD & rhs) const {
	// dynamic cast parent class to child class
	const Comedy* rhsCasted = dynamic_cast<const Comedy*>(&rhs);
	// true if the movie's release year and title is the same
	return (releaseYear == rhsCasted->releaseYear && title == rhsCasted->title);
}

//-------------------------------operator==------------------------------------
// Returns true if rhs doesn't have the same title and release year.
//-----------------------------------------------------------------------------
bool Comedy::operator!=(const DVD & rhs) const {
	// true if lhs is not equal to rhs
	return !(*this == rhs);
}

//-------------------------------operator==------------------------------------
// Returns true if title is alphanumerically less than rhs' title. If they have
// the same title, returns true if year is less than rhs' year.
//-----------------------------------------------------------------------------
bool Comedy::operator<(const DVD & rhs) const {
	// dynamic cast parent class to child class
	const Comedy* rhsCasted = dynamic_cast<const Comedy*>(&rhs);
	// check with title
	if (title < rhsCasted->title)
		return true;
	// if same title, check with release year
	if (title == rhsCasted->title)
		if (releaseYear < rhsCasted->releaseYear)
			return true;
	// else, then false
	return false;
}

//-------------------------------operator==------------------------------------
// Returns true if title is alphanumerically less than rhs' title. If they have
// the same title, returns true if year is less than rhs' year.
//-----------------------------------------------------------------------------
bool Comedy::operator>(const DVD & rhs) const {
	// true if lhs is not equal nor smaller than rhs
	return !(*this == rhs || *this < rhs);
}

//-------------------------------borrowing-------------------------------------
// Returns false if stock is 0. Returns true and decreases stock by 1 if not.
//-----------------------------------------------------------------------------
bool Comedy::borrowing() {
    if (stock == 0) return false;
    stock--;
    return true;
}

//-------------------------------returning-------------------------------------
// Returns true and increases stock by 1.
//-----------------------------------------------------------------------------
bool Comedy::returning() {
    stock++;
    return true;
}
