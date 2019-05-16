#ifndef VIDEO_H
#define VIDEO_H
//Class object for video has title, genre, quantity, and rating
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//constants
const int MAXCHAR = 101;
//enumerated data type for Genre
enum Genre {ACTION, FAMILY, COMEDY, HORROR, ILLEGAL};
//data type for Video
class Video
{
    private:
		char *title;
    	Genre genre;
    	int qty;
    	double rating;
	public:
		//constructors
		//default constructor
		Video();
		//constructor with parameters
		Video(char [], Genre, int, double);
		//copy constructor
		Video(const Video &aVideo);
		//destructor
		~Video();
		//mutator functions
		void setTitle(char []);
		void setGenre(Genre);
		void setQty(int);
		void setRating(double);
		//accessor functions
		void getTitle(char []) const;
		Genre getGenre() const;
		int getQty() const;
		double getRating() const;
		//print video
		void printVideo();
		void printVideo(ofstream &);
		//assignment operator overloading
		const Video& operator= (const Video& aVideo);		
};
Genre readGenre(char);
void printGenre(Genre, char []);

#endif

