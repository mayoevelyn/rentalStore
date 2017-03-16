#include "classic.h"

//---------------------------------setData-------------------------------------
// Takes in a string and sets data.
//-----------------------------------------------------------------------------
void Classic::setData(string data) {
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

	// process the stream into containers and release date
	string firstName, lastName;
	stream >> firstName >> lastName >> releaseMonth >> releaseYear;

	// set major actor's name
	majorActor = firstName + " " + lastName;
}

<<<<<<< HEAD
//----------------------------------getDvdType---------------------------------
// Returns the DVD type.
//-----------------------------------------------------------------------------
char Classic::getDvdType() const {
    return dvdType;
}

//----------------------------------getStock-----------------------------------
// Returns the stock amount.
//-----------------------------------------------------------------------------
int Classic::getStock() const {
    return stock;
}

//----------------------------------getDirector--------------------------------
// Returns the director.
//-----------------------------------------------------------------------------
string Classic::getDirector() const {
    return director;
}

//----------------------------------getTitle-----------------------------------
// Returns the title.
//-----------------------------------------------------------------------------
string Classic::getTitle() const {
    return title;
}

//-------------------------------getReleaseYear--------------------------------
// Returns the releaseYear.
//-----------------------------------------------------------------------------
int Classic::getReleaseYear() const {
    return releaseYear;
}

//-------------------------------getReleaseYear--------------------------------
// Returns the releaseMonth.
//-----------------------------------------------------------------------------
int Classic::getReleaseMonth() const {
    return releaseMonth;
}

//-------------------------------setReleaseYear--------------------------------
// Sets the releaseYear to the parameter
//-----------------------------------------------------------------------------
void Classic::setReleaseMonth(int newReleaseMonth) {
    releaseMonth = newReleaseMonth;
}

//-------------------------------setReleaseYear--------------------------------
// Sets the releaseYear to the parameter.
//-----------------------------------------------------------------------------
void Classic::setReleaseYear(int newReleaseYear) {
    releaseYear = newReleaseYear;
}

//-------------------------------setMajorActor---------------------------------
// Sets the majorActor to the parameter.
//-----------------------------------------------------------------------------
void Classic::setMajorActor(string newMajorActor) {
    majorActor = newMajorActor;
}

//----------------------------------display------------------------------------
// Displays the following, each separated by commas:
// Dvd type, stock, director, title, release year
//-----------------------------------------------------------------------------
void Classic::display() const {
    cout << dvdType << ", " << stock << ", " << director << ", " << title
        << ", " << majorActor << " " << releaseMonth << " " << releaseYear;
=======
void Classic::display()
{
	cout << dvdType << stock << director << title << majorActor << releaseMonth << releaseYear << endl;
>>>>>>> a19171376175ec33f2f547b2f18236d09d02fed6
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
