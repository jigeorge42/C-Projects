#include "Creatures.h"

void displayMenu()			//Menu
{
	cout<<"What would you like to do?"<<endl;
	cout<<"	1.	Enter new magical creatures or load from file."<<endl;
	cout<<"	2.	Print all creatures."<<endl;
	cout<<"	3.	Print statistics on creature cost."<<endl;
	cout<<"	4.	End program."<<endl;
	cout<<"	Enter 1, 2, 3, or 4."<<endl;
	cout<<"CHOICE: ";
	
	return;
}

int enterCreatures(Creatures array[], int num)		//Choice #1
{
	int userChoice;
	ifstream infile;
	string filename;
	string data;
	
	if(num != 100)
				{
					cout<<"What do you want to do?"<<endl;
					cout<<"	1.	Load my creatures from a file."<<endl;
					cout<<"	2.	Enter one manually."<<endl;
					cout<<"	Choose 1 or 2."<<endl;
					cout<<"CHOICE: ";
					cin>>userChoice;
						while(userChoice < 1 || userChoice > 2)		//sub menu of Choice 1
						{
							cout<<"Please enter 1 or 2."<<endl;
							cout<<"CHOICE: ";
							cin>>userChoice;
						}
					cout<<endl<<endl;
					
					if(userChoice == 1)		//sub menu choice 1
					{
						cout<<"What is the name of the file with your list of creatures? (ex: filename.txt)"<<endl;
						cout<<"FILENAME: ";
						cin>>filename;
						
						infile.open(filename.c_str());
							if(!infile.is_open()){
								cout<<filename<<" does not exist or is corrupt. sorry. Can't load creatures."<<endl<<endl;
								return 1;
							}
						
						if(infile.good())		//Loads the data from file
						{
							
							while(!infile.eof())
							{
								getline(infile, array[num].name, '#');
								
								getline(infile,array[num].descrip,'#');
								
								getline(infile,data,'#');
								array[num].avgLength = convertToFloat(data);
								getline(infile,data,'#');
								array[num].avgHeight = convertToFloat(data);
								getline(infile,array[num].location,'#');
								getline(infile,array[num].dangerous,'#');
								getline(infile,data,'#');
								array[num].creatureCost.hours = convertToFloat(data);
								getline(infile,data,'#');
								array[num].creatureCost.costPerHour = convertToFloat(data);
								getline(infile,data,'#');
								array[num].creatureCost.food = convertToFloat(data);
								getline(infile,data,'#');
								array[num].creatureCost.misc = convertToFloat(data);
								
								
								num++;
							}
							infile.close();
							cout<<num<<" creatures from "<<filename<<" have been added to the program."<<endl<<endl;
						}
							
					}
					
						else{		//Enter the Creature manually 
		
						cout<<"NAME: ";
						cin.ignore();
						getline(cin,array[num].name);
						cout<<endl<<endl;
						
						cout<<"DESCRIPTION: ";
						getline(cin,array[num].descrip);
						cout<<endl<<endl;
						
						cout<<"AVERAGE LENGTH (in feet): ";
						cin>>array[num].avgLength;
						cout<<endl<<endl;
						
						cout<<"AVERAGE HEIGHT (in feet): ";
						cin>>array[num].avgHeight;
						cout<<endl<<endl;
						
						cout<<"LOCATION: ";
						cin.ignore();
						getline(cin,array[num].location);
						cout<<endl<<endl;
						
						cout<<"IS IT A DANGEROUS CREATURE? (y or n): ";
						getline(cin,array[num].dangerous);
						cout<<endl<<endl<<endl;
						
						cout<<"How many hours do you spend caring for the "<<array[num].name<<"?"<<endl;
						cout<<"NUM HOURS: ";
						cin>>array[num].creatureCost.hours;
						
						cout<<"What is the cost per hour for caring for the "<<array[num].name<<"?"<<endl;
						cout<<"COST PER HOUR: ";
						cin>>array[num].creatureCost.costPerHour;
						
						cout<<"How much money do you spend on food for the "<<array[num].name<<"?"<<endl;
						cout<<"FOOD COST: ";
						cin>>array[num].creatureCost.food;
						
						cout<<"How much money do you spend on grooming and medical supplies for the "<<array[num].name<<"?"<<endl;
						cout<<"SUPPLY COST: ";
						cin>>array[num].creatureCost.misc;
						cout<<endl;
						
						cout<<"The "<<array[num].name<<" has been added."<<endl<<endl;
						num++;
						}
				}
	return num;
}

float convertToFloat (string s)
{
	istringstream mystring(s);
	float myfloat;
	if (!(mystring >> myfloat))
		myfloat = 0;
	return myfloat;
}

void printCreatures(Creatures array[], int num)		//Choice 2
{
	cout<<"--------------------"<<endl;
if(num == 0)
{
	cout<<"There are no creatures in your zoo."<<endl<<endl;
}	
else{			//Prints the creatures
	
	for(int i = 0;i < num; i++)
	{
	cout<<"CREATURE "<<i+1<<":"<<endl;
	
	cout<<"Name:	"<<array[i].name<<endl;
	cout<<"DESCRIPTION:"<<endl;
	cout<<array[i].descrip<<endl;
	
	cout<<"Length:	"<<array[i].avgLength<<" feet"<<endl;
	cout<<"Height:	"<<array[i].avgHeight<<" feet"<<endl;
	cout<<"Location:	"<<array[i].location<<endl;
	cout<<"Dangerous?	"<<array[i].dangerous<<endl;
	cout<<"Number of HOurs to Care for Creature:	$"<<array[i].creatureCost.hours<<endl;
	cout<<"Cost Per Hour of Taking Care of Creature:	$"<<array[i].creatureCost.costPerHour<<endl;
	cout<<"Cost to Feed Creature:	$"<<array[i].creatureCost.food<<endl;
	cout<<"Grooming & Supplies Cost:	$"<<array[i].creatureCost.misc<<endl<<endl;
	}
}
return;
}
	
void printStatistics(Creatures array[],int num)		//prints the cost for each creature
{
	double cost;
	double Tcost;
	cost = 0;
	Tcost = 0;
	cout<<"COST OF EACH CREATURE FOR ONE WEEK:"<<endl<<endl;

	cout<<"CREATURE	COST"<<endl;
	for(int i =0; i < num; i++){
	cost = array[i].creatureCost.hours*array[i].creatureCost.costPerHour+array[i].creatureCost.food+array[i].creatureCost.misc;
	cout<<array[i].name<<"		$"<<cost<<endl;
	Tcost = Tcost + cost;
	}
	
	
	cout<<"TOTAL COST:"<<"		$"<<Tcost;
	cout<<endl<<endl;

return;
}

void saveCreaturesToFile(Creatures array[], int num)
{
	string file;
	ofstream outFS;
	int i = 0;
	char ans;
	
	cout<<"Do you want to save your creature list to a file? (y or n)";
	cin>>ans;
	cout<<endl<<endl;
	
	if(ans == 'y' || ans== 'Y')		//saves the creatures if answer is y
	{
	
	cout<<"What is the name of the file you want to save your creatures to?"<<endl;
	cin>>file;
	cout<<endl<<endl;
	

	outFS.open(file.c_str());
	if(!outFS.is_open()){
		cout<<file<<" does not exist or is corrupt. Sorry. Can't save creatures."<<endl<<endl;
		return;
		}
		for(i = 0; i< num; i++)
		{
		outFS <<array[i].name<<"#";
		outFS <<array[i].descrip<<"#";
		outFS <<array[i].avgLength<<"#";
		outFS <<array[i].avgHeight<<"#";
		outFS <<array[i].location<<"#";
		outFS <<array[i].dangerous<<"#";
		outFS <<array[i].creatureCost.hours<<"#";
		outFS <<array[i].creatureCost.costPerHour<<"#";
		outFS <<array[i].creatureCost.food<<"#";
		if(i == num-1){
		outFS <<array[i].creatureCost.misc;
		}
		else{		
		outFS <<array[i].creatureCost.misc<<"#";
		}
		}
		
		cout<<"Your creatures were successfully saved to "<<file<<" file."<<endl<<endl;
	}
	
	else{		//if n, then exits without saving 
	cout<<"GOODBYE!"<<endl<<endl;
	}
		return;
	
}
		
