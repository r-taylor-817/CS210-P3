#ifndef PROJECT_3_WITH_MAPS_INVENTORYSEARCH_H
#define PROJECT_3_WITH_MAPS_INVENTORYSEARCH_H

#include <iostream>
#include <map>	//Map class is included
#include <string>	//Use of strings is included
#include<fstream>	//File stream is included

using namespace std;

class InventorySearch
{
		//Public member function declarations
	public:
		//Functions to interact with files
		void readFile(string fileName);	//Reads input from file and saves item frequency
		void outputFile(string fileName);	//Outputs item name and frequency to new file
		
		void printInventory();	//Prints histogram of item names and frequencies
		void searchInventory(string itemInput);	//Returns item name and frequency of grocery item from user input
		void printHistogram();	//Prints full list of item names and frequencies
		void quitMenu();	//Quits the application

		void printMenu();	//Prints user input menu

		//Private members 
	private:
		map<string, int> Groceries;	//Map for item name and frequency
}; 
#endif