#ifndef CREATURES_H
#define CREATURES_H


#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

struct Cost{		//cost structure
	float hours;
	float costPerHour;
	float food;
	float misc;
};

struct Creatures{		//main structure
	string name;
	string descrip;
	float avgLength;
	float avgHeight;
	string location;
	string dangerous;
	Cost creatureCost;
};
		//Prototypes
float convertToFloat(string);

void displayMenu();

int enterCreatures(Creatures[], int);

void printCreatures(Creatures[],int);

void printStatistics(Creatures[],int);

void saveCreaturesToFile(Creatures[],int);

#endif