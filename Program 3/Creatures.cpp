/*
	Title: Program3
	Author: Joshua George
	Date: November 13, 2017
	Purpose:  a program for the Magical Creatures Zookeeper named Hagrid. 
*/

#include "Creatures.h"

int main ()
{
	const int MAX_CREATURES = 100;
	Creatures creaturesArray[MAX_CREATURES];
	int numCreatures = 0;
	bool stay = true;
	int mainInput;
	
	
	do
	{
		displayMenu();		//Main menu
		cin>>mainInput;
			while(mainInput < 1 || mainInput > 5)
			{
				cout<<"Invalid input. Please enter a number between 1 - 5.";
				cout<<"CHOICE: ";
				cin>>mainInput;
			}
		cout<<endl<<endl;
		
			switch (mainInput)		//Functions bases on user choice
			{
				case 1:
					numCreatures = enterCreatures(creaturesArray, numCreatures);
					break;
			
				case 2:
					printCreatures(creaturesArray,numCreatures);
					break;
					
				case 3:
					printStatistics(creaturesArray,numCreatures);
					break;
					
				case 4:
					saveCreaturesToFile(creaturesArray,numCreatures);
					break;
				}
}while(mainInput != 4);
		
	
	
	
return 0;
}