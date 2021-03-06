//------------------------------drama.cpp--------------------------------------
// Drama class: Implements a DVD that is drama type movie.
//  Inherits from DVD
//  Sorted by direector, then title.
//-----------------------------------------------------------------------------
#include "drama.h"

//-------------------------------processInfo-----------------------------------
// Takes in a string and sets it as the release year.
//-----------------------------------------------------------------------------
void Drama::setData(string data) {
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
// Takes in a string and sets director, then title.
//-----------------------------------------------------------------------------
void Drama::setTransData(string data)
{
	// change param string into sstream
	stringstream stream(data);
	// container to be reused for holding data
	string str;

	// set director
	getline(stream, str, ',');
	director = str;
	// set title
	getline(stream, str, ',');
	title = str;
}

//----------------------------------getDvdType---------------------------------
// Returns the DVD type.
//-----------------------------------------------------------------------------
char Drama::getDvdType() const {
    return dvdType;
}

//----------------------------------getStock-----------------------------------
// Returns the stock amount.
//-----------------------------------------------------------------------------
int Drama::getStock() const {
    return stock;
}

//----------------------------------getDirector--------------------------------
// Returns the director.
//-----------------------------------------------------------------------------
string Drama::getDirector() const {
    return director;
}

//----------------------------------getTitle-----------------------------------
// Returns the title.
//-----------------------------------------------------------------------------
string Drama::getTitle() const {
    return title;
}

//-------------------------------getReleaseYear--------------------------------
// Returns the releaseYear.
//-----------------------------------------------------------------------------
int Drama::getReleaseYear() const {
    return releaseYear;
}

//----------------------------------setDirector--------------------------------
// Set director to the passed in director.
//-----------------------------------------------------------------------------
void Drama::setDirector(string newDirector) {
    director = newDirector;
}

//----------------------------------setTitle-----------------------------------
// Set title to the passed in title.
//-----------------------------------------------------------------------------
void Drama::setTitle(string newTitle) {
    title = newTitle;
}

//----------------------------------display------------------------------------
// Displays the following, each separated by commas:
// Dvd type, stock, director, title, release year
//-----------------------------------------------------------------------------
void Drama::display() const {
    cout << dvdType << ", " << stock << "," << director << "," << title
        << ", " << releaseYear << endl;
}

//-----------------------------------print-------------------------------------
// Outputs the following, each separated by commas:
// Dvd type, stock, director, title, release year
//-----------------------------------------------------------------------------
void Drama::print(ostream& output) const {
    output << dvdType << ", " << stock << "," << director << "," << title
        << ", " << releaseYear << endl;
}

//-------------------------------operator==------------------------------------
// Returns true if rhs has the same director and title.
//-----------------------------------------------------------------------------
bool Drama::operator==(const DVD & rhs) const {
	// dynamic cast parent class to child class
	const Drama* rhsCasted = dynamic_cast<const Drama*>(&rhs);
	// true if the movie's director and title is the same
	return (director == rhsCasted->director && title == rhsCasted->title);
}


//-------------------------------operator==------------------------------------
// Returns true if rhs do not have the same director or title.
//-----------------------------------------------------------------------------
bool Drama::operator!=(const DVD & rhs) const {
	// true if lhs is not equal to rhs
	return !(*this == rhs);
}

//-------------------------------operator==------------------------------------
// Returns true if director is alphanumerically less than rhs' director. 
// If they have the same director, then true if title is alphanumerically less.
//-----------------------------------------------------------------------------
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

//-------------------------------operator==------------------------------------
// Returns true if director is alphanumerically greater than rhs' director.  If
// they have the same director, then true if title is alphanumerically greater.
//-----------------------------------------------------------------------------
bool Drama::operator>(const DVD & rhs) const {
	// true if lhs is not equal nor smaller than rhs
	return !(*this == rhs || *this < rhs);
}

void Drama::addStock(DVD* toAdd) {
    if (*this == *toAdd) {
        const Drama* toAddCasted = dynamic_cast<const Drama*>(&*toAdd);
        stock += toAddCasted->stock;
    }
}