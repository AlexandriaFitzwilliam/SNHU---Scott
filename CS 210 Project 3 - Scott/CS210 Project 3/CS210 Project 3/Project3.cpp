/*
	Method: Project3.cpp

	Author: Alexandria Scott

	Creation Date: 2/22/26
*/

#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include "Produce.h"
#include "Inventory.h"
using namespace std;


// Function to display welcome message


// Function to show main menu
void PrintMainMenu() {
	cout << endl << "***************************************************" << endl;
	cout << "******************** Main Menu ********************" << endl;
	cout << "   1. Search for Item" << endl;
	cout << "   2. Print Numerical Frequencies for All Items" << endl;
	cout << "   3. Print Histogram for All Items" << endl;
	cout << "   4. Exit" << endl;
}


//Function to get user input and validate it
int ValidateUserInput() {
	// INIT user input
	int menuOption;

	// Turn on exceptions for failbit & badbit
	cin.exceptions(ios::failbit | ios::badbit);

	while (true) {
		try {
			// Checks if response is an int 1-4
			cin >> menuOption;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (menuOption <= 4 && menuOption > 0) {
				return menuOption;
			}
			else {
				cout << endl << "Sorry. Response must be 1-4" << endl;
			}
		}
		// Gives error message if response is not an integer.
		catch (ios_base::failure& excpt) {
			cout << "Sorry, that is not a valid response." << endl;

			// Clear input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		// Shows menu again if error.
		PrintMainMenu();
	}
}


// Main function
int main() {
	// INIT boolean variable for continuing with program.
	bool keepGoing = true;
	// INIT int for userInput.
	int userInput = 0;

	// INIT new inventory and load with produce items
	Inventory ourInventory("Items_Shopped.txt");
	// Create backup
	ourInventory.CreateBackup();
	
	// WHILE still continuing with program.
	while (keepGoing) {
		//Print main menu
		PrintMainMenu();
		// Get user response
		userInput = ValidateUserInput();

		// If option 1, go to search for item
		if (userInput == 1) {
			ourInventory.SearchInventory();
		}
		// If option 2, go to print numerical frequencies
		else if (userInput == 2) {
			ourInventory.PrintInventoryList();
		}
		// If option 3, go to print histogram
		else if (userInput == 3) {
			ourInventory.PrintInventoryHistogrm();
		}
		// If option 4, exit program
		else if (userInput == 4) {
			cout << endl << "Goodbye." << endl;
			keepGoing = false;
		}
		// Else, give an error message, should never be seen
		else {
			cout << endl << "FIXME: THIS IS NOT AN OPTION AND SHOULD NOT BE VISIBLE." << endl;
		}
	}

	return 0;
}