//This is the implementation file for video.h (the Video class)
#include "video.h"

//default constructor
Video::Video()
{
	//allocate memory for title
	title = new char[MAXCHAR];
	strcpy(title, "No title");
	genre = ILLEGAL;
	qty = 0;
	rating =0;
}

//constructor with parameters
Video::Video(char tempTitle[], Genre tempGenre, int tempQty, double tempRating)
{
	//allocate memory
	title = new char[strlen(tempTitle) + 1];
	strcpy(title, tempTitle);
	genre = tempGenre;
	qty = tempQty;
	rating = tempRating;
}

//Copy Constructor
Video::Video(const Video &aVideo)
{
	title = new char[strlen(aVideo.title) + 1];
	*this = aVideo;
}


//destructor
Video::~Video()
{
	//deallocate memory for title
	if(title)
	{
		delete [] title;
		title = NULL;
	}
}

//mutator functions
void Video::setTitle(char newTitle[])
{
	//if title exists, delete and reallocate just enough for newTitle
	if(title)
	{
		delete [] title;
		title = NULL;
	}
	title = new char[strlen(newTitle)+1];
	strcpy(title, newTitle);
}

void Video::setGenre(Genre newGenre)
{
	genre = newGenre;
}

void Video::setQty(int newQty)
{
	qty = newQty;
}

void Video::setRating(double newRating)
{
	rating = newRating;
}

//accessor functions
void Video::getTitle(char returnTitle[]) const
{
	strcpy(returnTitle, title);
}

Genre Video::getGenre() const
{
	return genre;
}

int Video::getQty() const
{
	return qty;
}

double Video::getRating() const
{
	return rating;
}

//prints to console
void Video::printVideo()
{
	char genreDesc[MAXCHAR];
	printGenre(this->genre, genreDesc);
	cout << title << ';' << genreDesc << ';' << qty << ';' << rating << endl;
}

//prints to file
void Video::printVideo(ofstream &outFile)
{
	char genreDesc[MAXCHAR];
    printGenre(this->genre, genreDesc);
	outFile << title << ';' << genreDesc << ';' << qty << ';' << rating << endl;
}	


//This function assigns a Genre based on the letter and returns the Genre
Genre readGenre(char letter)
{
    Genre tempGenre;
    switch(tolower(letter))
    {
        case 'a':
            tempGenre = static_cast<Genre>(0);
            break;
        case 'f':
            tempGenre = static_cast<Genre>(1);
            break;
        case 'c':
            tempGenre = static_cast<Genre>(2);
            break;
        case 'h':
            tempGenre = static_cast<Genre>(3);
            break;
        default:
            tempGenre = static_cast<Genre>(4);
    }
    return tempGenre;
}

//This function populates the genreDesc based on the Genre
void printGenre(Genre tempGenre, char genreDesc[])
{
    switch(tempGenre)
    {
        case 0:
            strcpy(genreDesc, "ACTION");
            break;
        case 1:
            strcpy(genreDesc, "FAMILY");
            break;
        case 2:
            strcpy(genreDesc, "COMEDY");
            break;
        case 3:
            strcpy(genreDesc, "HORROR");
            break;
        case 4:
            strcpy(genreDesc, "ILLEGAL");
            break;
    }
    return;
}

//assignment operator overloaded
const Video& Video::operator= (const Video& aVideo)
{
	//if it is a self copy, don't do anything
	if (this == &aVideo)
		return *this;
	//make current object *this a copy of the passed in student
	else
	{
		//strncpy(this->title, aVideo.title, strlen(aVideo.title) + 1);
		this->setTitle(aVideo.title);
		this->qty = aVideo.qty;
		this->genre = aVideo.genre;
		this->rating = aVideo.rating;

		return *this;
	}
}
