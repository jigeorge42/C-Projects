/*
	Title:  Movie.cpp
	Author:  April Crockett, modified by Joshua George******************************************************
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#include "Movie.h"
#include "Text.h"

//FIXME:  add the overloaded createMovie function!****************************************************************
Movie* createMovie(Text* title, int length, int year, Text* genre, Text* rating, int numOscars, float numStars)
{
	Movie* myMovie = new Movie;
	
	myMovie->movieTitle = title;
	myMovie->movieLength = length;
	myMovie->movieYear = year;
	myMovie->movieGenre = genre;
	myMovie->movieRating = rating;
	myMovie->movieOscars = numOscars;
	myMovie->movieNumStars = numStars;
	
	return myMovie;
}

//FIXME:  add the editMovie function!*****************************************************************************
void editMovie(Movie* myMovie)
{
	int Length;
	int Year;
	int oscars;
	float Stars;
	char tempString[100];
	int input = 0;
	do{
		cout<<"Which detail do you wish to edit?"<<endl;
		cout<<"	1.	Title"<<endl;
		cout<<"	2.	Length"<<endl;
		cout<<"	3.	Year"<<endl;
		cout<<"	4.	Genre"<<endl;
		cout<<"	5.	Rating"<<endl;
		cout<<"	6.	Number of Oscars won"<<endl;
		cout<<"	7.	Number of Stars"<<endl;
		cout<<"	8.	DONE EDITING"<<endl;
		cout<<"CHOOSE 1-8:";
		cin>>input;
			while(input < 1 || input > 8)
			{
				cout<<"Please choose 1 - 8"<<endl;
				cin>>input;
				cout<<endl<<endl;
			}
		cout<<endl<<endl;
		
		switch (input)
		{
			case 1:
				cout<<"Current Title: "<<myMovie->movieTitle<<endl;
				cout<<"NEW Title: ";
				cin.ignore();
				cin.getline(tempString,100);
				
				destroyText(myMovie->movieTitle);
				myMovie->movieTitle = createText(tempString);
				cout<<endl<<endl;
			
				break;
			
			case 2:
				cout<<"Current Length: "<<myMovie->movieLength<<endl;
				cout<<"NEW LENGTH: ";
				cin>>Length;
				myMovie->movieLength = Length;
				cout<<endl<<endl;
				
				break;
				
			case 3:
				cout<<"Current Year: "<<myMovie->movieYear<<endl;
				cout<<"NEW YEAR: ";
				cin>>Year;
				myMovie->movieYear = Year;
				cout<<endl<<endl;
				
				break;
				
			case 4:
				cout<<"Current Genre: "<<myMovie->movieGenre<<endl;
				cout<<"NEW GENRE: ";
				cin.ignore();
				cin.getline(tempString,100);
				
				destroyText(myMovie->movieGenre);
				myMovie->movieGenre = createText(tempString);
				cout<<endl<<endl;
				
				break;
				
			case 5:
				cout<<"Current Rating: "<<myMovie->movieRating<<endl;
				cout<<"NEW RATING: ";
				cin.ignore();
				cin.getline(tempString,100);
				
				destroyText(myMovie->movieRating);
				myMovie->movieRating = createText(tempString);
				cout<<endl<<endl;
				
				break;
				
			case 6:
				cout<<"Current Oscars: "<<myMovie->movieOscars<<endl;
				cout<<"NEW NUMBER OF OSCARS: ";
				cin>>oscars;
				
				myMovie->movieOscars = oscars;
				cout<<endl<<endl;
				
				break;
			
			case 7:
				cout<<"Current Stars: "<<myMovie->movieNumStars<<endl;
				cout<<"NEW NUMBER OF STARS: ";
				cin>>Stars;
				
				myMovie->movieNumStars = Stars;
				cout<<endl<<endl;
				
				break;
				
			case 8:
				break;
		}
	}while(input < 8);
}

Movie* createMovie(Text* title, int length)
{
	//dynamically allocate a new Movie
	Movie* myMovie = new Movie;
	
	//assign parameter data to structure memebers
	myMovie->movieTitle = title;
	myMovie->movieLength = length;
	
	return myMovie;
}

void destroyMovie(Movie* myMovie)
{
	destroyText(myMovie->movieTitle);
	destroyText(myMovie->movieGenre);
	destroyText(myMovie->movieRating);
	delete myMovie;
}

void printMovieDetails(Movie* myMovie)
{
	cout << endl;
	cout << right << setw(30) << "Movie Title:  " << left;
	displayText(myMovie->movieTitle);
	cout << endl;
	cout << right << setw(30) << "Length (minutes):  " << left << myMovie->movieLength << endl;
	cout << right << setw(30) << "Year Released:  " << left << myMovie->movieYear << endl;
	cout << right << setw(30) << "Genre:  " << left;
	displayText(myMovie->movieGenre);
	cout << endl;
	cout << right << setw(30) << "Rating:  " << left;
	displayText(myMovie->movieRating);
	cout << endl;
	cout << right << setw(30) << "Number of Oscars Won:  " << left << myMovie->movieOscars << endl;
	cout << right << setw(30) << "Number of Stars:  " << left << myMovie->movieNumStars << endl << endl;
}

void printMovieDetailsToFile(Movie* myMovie, ofstream &outFile)
{
	char temp[1000];
	strncpy(temp, getText(myMovie->movieTitle), 1000);
	outFile << temp << endl;
	outFile << myMovie->movieLength << endl;
	outFile << myMovie->movieYear << endl;
	strncpy(temp, getText(myMovie->movieGenre), 1000);
	outFile << temp << endl;
	strncpy(temp, getText(myMovie->movieRating), 1000);
	outFile << temp << endl;
	outFile << myMovie->movieOscars << endl;
	outFile << myMovie->movieNumStars << endl;
}

Text* getMovieTitle(Movie* myMovie)
{
	return myMovie->movieTitle;
}

int getMovieLength(Movie* myMovie)
{
	return myMovie->movieLength;
}

int getMovieYear(Movie* myMovie)
{
	return myMovie->movieYear;
}

Text* getMovieGenre(Movie* myMovie)
{
	return myMovie->movieGenre;
}

Text* getMovieRating(Movie* myMovie)
{
	return myMovie->movieRating;
}

int getMovieOscars(Movie* myMovie)
{
	return myMovie->movieOscars;
}

float getMovieNumStars(Movie* myMovie)
{
	return myMovie->movieNumStars;
}

void setMovieTitle(Movie* myMovie, Text* title)
{
	myMovie->movieTitle = title;
}

void setMovieLength(Movie* myMovie, int length)
{
	myMovie->movieLength = length;
}

void setMovieYear(Movie* myMovie, int year)
{
	myMovie->movieYear = year;
}

void setMovieGenre(Movie* myMovie, Text* genre)
{
	myMovie->movieGenre = genre;
}

void setMovieRating(Movie* myMovie, Text* rating)
{
	myMovie->movieRating = rating;
}

void setMovieOscars(Movie* myMovie, int oscars)
{
	myMovie->movieOscars = oscars;
}

void setMovieNumStars(Movie* myMovie, float stars)
{
	myMovie->movieNumStars = stars;
}
