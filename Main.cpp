#include "InventorySearch.h"
#include <iostream>

int main() {
	InventorySearch GroceryItems;	//GroceryItems object is created
	string inputItem;
	int userChoice;


	GroceryItems.readFile("Inventory.txt");	//Inventory.txt contents are read into a map
	GroceryItems.outputFile("Frequency.dat");	//Map contents from Inventory.txt are backed up into new file


	do {	//Main loop of application to run until user prompts to quit

		GroceryItems.printMenu();	//printMenu function is called to print main menu

		cin >> userChoice;	//User is prompted for menu choice


		if (userChoice == 1) {	//If user inputs 1, they are prompted for item name and searchInventory function is called
			cout << "Enter item name: " << endl;
			//cout << "Enter 'Break' to exit" << endl;
			cin >> inputItem;
			GroceryItems.searchInventory(inputItem);
		}

		else if (userChoice == 2) {	//If user inputs 2, a list of items with their associated frequencies is printed
			GroceryItems.printInventory();
		}

		else if (userChoice == 3) {	//If user inputs 3, a list of items with their frequencies is printed as a histogram
			GroceryItems.printHistogram();
		}

		else if (userChoice == 4) {	//If user inputs 4, the application is exited
			GroceryItems.quitMenu();
		}

	} while (userChoice != 4);

}