//---------------------------------comedy.cpp----------------------------------
// Comedy class: Implements a DVD that is comedy type movie. 
//  Inherits from DVD
//  Sorted first by title, then by release year.
//-----------------------------------------------------------------------------

#include "comedy.h"

//---------------------------------setData-------------------------------------
// Takes in a string and sets all data.
//-----------------------------------------------------------------------------
void Comedy::setData(string data) {
	// change param string into sstream
	stringstream stream(data);
	// container to be reused for holding data
	string str;

	// set dvdType
	getline(stream, str, ',');
	dvdType = str[0];
	// set stock
	getline(stream, str, ',');
	stock = stoi(str);
	// set director
	getline(stream, str, ',');
	director = str;
	// set title
	getline(stream, str, ',');
	title = str;
	// sets the release year
	stream >> releaseYear;
}

//-------------------------------setTransData----------------------------------
// Takes in a string and sets title and release year.
//-----------------------------------------------------------------------------
void Comedy::setTransData(string data) {
	// change param string into sstream
	stringstream stream(data);
	// container to be reused for holding data
	string str;

	// set title
	getline(stream, str, ',');
	title = str;
	// sets the release year
	stream >> releaseYear;
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
	cout << dvdType << ", " << stock << "," << director << "," << title
		<< ", " << releaseYear << endl;
}

//-----------------------------------print-------------------------------------
// Outputs the following, each separated by commas:
// Dvd type, stock, director, title, release year
//-----------------------------------------------------------------------------
void Comedy::print(ostream& output) const {
    output << dvdType << ", " << stock << "," << director << "," << title
        << ", " << releaseYear << endl;
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

//-------------------------------operator!=------------------------------------
// Returns true if rhs doesn't have the same title and release year.
//-----------------------------------------------------------------------------
bool Comedy::operator!=(const DVD & rhs) const {
	// true if lhs is not equal to rhs
	return !(*this == rhs);
}

//-------------------------------operator<-------------------------------------
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

//-------------------------------operator>-------------------------------------
// Returns true if title is alphanumerically less than rhs' title. If they have
// the same title, returns true if year is less than rhs' year.
//-----------------------------------------------------------------------------
bool Comedy::operator>(const DVD & rhs) const {
	// true if lhs is not equal nor smaller than rhs
	return !(*this == rhs || *this < rhs);
}

void Comedy::addStock(DVD* toAdd) {
    if (*this == *toAdd) {
        const Comedy* toAddCasted = dynamic_cast<const Comedy*>(&*toAdd);
        stock += toAddCasted->stock;
    }
}
