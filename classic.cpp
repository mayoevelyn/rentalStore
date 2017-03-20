//---------------------------------classic.cpp----------------------------------
// Classic class: Implements a DVD that is classic type movie. 
//  Inherits from DVD
//  Sorted first by release date, then major actor.
//-----------------------------------------------------------------------------
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
	string actor = firstName + " " + lastName;
    majorActor.push_back(actor);
}

//-------------------------------setTransData----------------------------------
// Takes in a string and sets release date then major actor
//-----------------------------------------------------------------------------
void Classic::setTransData(string data)
{
	// change param string into sstream
	stringstream stream(data);

	// process the stream into containers and release date
	string firstName, lastName;
	stream >> releaseMonth >> releaseYear >> firstName >> lastName;

	// set major actor's name
    string actor = firstName + " " + lastName;
    majorActor.push_back(actor);
}

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
    majorActor.push_back(newMajorActor);
}

//----------------------------------display------------------------------------
// Displays the following, each separated by commas:
// Dvd type, stock, director, title, major actor, release month, release year
//-----------------------------------------------------------------------------
void Classic::display() const {
    for (string actor : majorActor) {
        cout << dvdType << ", " << stock << ", " << director << ", " << title
            << ", " << actor << " " << releaseMonth << " " << releaseYear 
            << endl;
    }
}

//------------------------------------print------------------------------------
// Outputs the following, each separated by commas:
// Dvd type, stock, director, title, major actor, release month, release year
//-----------------------------------------------------------------------------
void Classic::print(ostream& output) const {
    for (string actor : majorActor) {
        output << dvdType << ", " << stock << ", " << director << ", " << title
            << ", " << actor << " " << releaseMonth << " " << releaseYear
            << endl;
    }
}

//-------------------------------operator==------------------------------------
// Returns true if rhs has the same major actor and release date.
//-----------------------------------------------------------------------------
bool Classic::operator==(const DVD & rhs) const {
	// dynamic cast parent class to child class
	const Classic* rhsCasted = dynamic_cast<const Classic*>(&rhs);
	// true if the movie's major actor and release date is the same

    //check if same major actors
    bool sameActor = false;
    auto rhsIter = majorActor;
    for (auto i = begin(rhsIter); i != end(rhsIter); ++i) {
        for (string actor : rhsCasted->majorActor) {
            if (actor == (*i)) sameActor = true;
        }
    }
    
    // check date first, if not the same, return false
    if (releaseMonth == rhsCasted->releaseMonth
        && releaseYear == rhsCasted->releaseYear) {
    // if shares a common major actor or title
        if (sameActor || title == rhsCasted->title) return true;
    }
    return false;
}

//-------------------------------operator!=------------------------------------
// Returns true if rhs does not have the same major actor and release date.
//-----------------------------------------------------------------------------
bool Classic::operator!=(const DVD & rhs) const {
	// true if lhs is not equal to rhs
	return !(*this == rhs);
}

//-------------------------------operator<-------------------------------------
// Returns true if rhs's release year is later. If same release year, true
// if major actor's name is alphanumerically greater.
//-----------------------------------------------------------------------------
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
		if(majorActor.front() < rhsCasted->majorActor.front())
			return true;
	// else, then false
	return false;
}

//-------------------------------operator>-------------------------------------
// Returns true if rhs's release year is earlier. If same release year, true
// if major actor's name is alphanumerically smaller.
//-----------------------------------------------------------------------------
bool Classic::operator>(const DVD & rhs) const {
	// true if lhs is not equal nor smaller than rhs
	return !(*this == rhs || *this < rhs);
}

void Classic::addStock(DVD* toAdd) {
    if (*this == *toAdd) {
        //cast to classic
        const Classic* toAddCasted = dynamic_cast<const Classic*>(&*toAdd);

        // add unique actors
        auto toAddIter = toAddCasted->majorActor;
        for (auto i = begin(toAddIter); i != end(toAddIter); ++i) {
            bool alreadyContains = false;
            for (string actor : majorActor) {
                if (actor == (*i)) alreadyContains = true;
            }
            if (!alreadyContains) majorActor.push_back(*i);
        }
        stock += toAddCasted->stock;
    }
}