#include "InventorySearch.h"
#include <iostream>
#include <map>

void InventorySearch::readFile(string fileName) {	//Reads input file contents into map
	string item;

	ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile.is_open()) {	//Assures that inputFile opened successfully
		string item;  
		while (inputFile >> item) {	//Iterates through inputFile until all items are assigned

			Groceries[item] ++;

		}

		inputFile.close();	//Input file is closed
	}

	else if (!inputFile.is_open()) {	//If inputFile can not be opened, error message is displayed
		cout << "Unable to open input file." << endl;
	}
	}


	void InventorySearch::outputFile(string fileName) {	//Function to print grocery data to backup file
		ofstream outputFile;
		outputFile.open(fileName);	//Opens output file

		if (outputFile.is_open()) {	//Prints key-value pairs of Groceries map while outputFile is open

			for (auto item : Groceries) {	//Prints map contents to outputFile
				outputFile << item.first << " " << item.second << endl;
			}
		}

		else if (!outputFile.is_open()) {	//Prints error statement if outputFile can not be opened
			cout << "Could not open output file." << endl;
		}

		outputFile.close();	//Output file is closed

	}
	
	
	void InventorySearch::searchInventory(string inputItem) {	//Searches grocery item inventory for user specified item

		if (Groceries.find(inputItem) != Groceries.end()) {	//If inputItem is found, print item name with value
			cout << inputItem << ": " << Groceries[inputItem] << endl;
		}

		else {	//Error statement if item is not found
			cout << "Item not found." << endl;
		}
		cout << endl;
	}
	
	
	void InventorySearch::printInventory() {	//Prints grocery item inventory with item frequencies
		for (auto item : Groceries) {	//Prints map contents
			cout << item.first << " " << item.second << endl;
		}
		cout << endl;
	}


	void InventorySearch::printHistogram() {	//Prints grocery item inventory with item frequencies as histogram

		string item;
		int frequency;

		ifstream inputFile;		//Item names and frequencies are read from "Frequency.dat" file
		inputFile.open("Frequency.dat");

		while (!inputFile.eof()) {	//Loop iterates until end of file is reached
			inputFile >> item; 
			inputFile >> frequency;

			cout << item << " ";
			for (int i = 0; i < frequency; ++i) {	//Loop to add asterisks according to item frequency
				cout << "*";
			}
			cout << endl;
		}

		cout << endl;

		inputFile.close();	//"Frequency.dat" is closed
		
	}


	void InventorySearch::quitMenu() {	//Quits the application
		exit(1);
	}


	void InventorySearch::printMenu() {	//Prints main menu for user to select choice
		cout << "        Welcome to Corner Grocer!" << endl;
		cout << "Please select an option from the menu below" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "1: Search item frequency" << endl;
		cout << "2: Print frequency report" << endl;
		cout << "3: Print frequency histogram" << endl;
		cout << "4: Quit" << endl;
		cout << endl;

	}