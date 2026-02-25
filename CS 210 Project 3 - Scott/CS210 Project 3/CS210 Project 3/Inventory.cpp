#include "Inventory.h"
#include <string>
#include <exception>
#include <fstream>

Inventory::Inventory(string txtFile) {
	// INIT input file stream.
	ifstream inFS;
	string fileItem;

	// Open file.
	inFS.open(txtFile);
	// Error message if cannot open file.
	if (!inFS.is_open()) {
		cout << "Could not open file Items_Shopped.txt" << endl;
	}
	while (getline(inFS, fileItem)) {
		// If the item name is not already in the list add it
		if (!AlreadyInList(fileItem)) {
			AddProduce(fileItem);
		}
		// Else just add 1 to the items counter
		else {
			PlusOneToCount(fileItem);
		}

	}
	// Close file.
	inFS.close();
}


void Inventory::AddProduce(string itemName) {
	// Create a new produce item
	Produce newProduce(itemName);
	// Add to vector
	inventoryList.push_back(itemName);
}


void Inventory::PrintInventoryList() {
	// for every item in list print it
	for (auto item : inventoryList) {
		item.PrintProduct();
	}
}


bool Inventory::AlreadyInList(string newName) {
	// Returns true/false if name is already in list
	bool alreadyIn = false;

	for (auto item : inventoryList) {
		if (item.GetName() == newName) {
			alreadyIn = true;
			break;
		}
	}
	return alreadyIn;
}


void Inventory::PlusOneToCount(string produceName) {
	// Finds item with the same name and increases count by 1
	for (auto& produce : inventoryList) {
		if (produce.GetName() == produceName) {
			produce.AddCount();
			return;
		}
	}
}


void Inventory::PrintInventoryHistogrm() {
	// For every item in the vector list
	int totalCount;

	for (auto item : inventoryList) {
		// Print the name
		cout << item.GetName() << " ";
		// Set the count
		totalCount = item.GetCount();
		// Print * and minus one to count until 0
		while (totalCount != 0) {
			cout << "*";
			totalCount -= 1;
		}
		cout << endl;
	}
}


void Inventory::SearchInventory() {
	// INIT user input
	string userInput;

	// Get user input
	cout << endl << "What item would you like to search for?" << endl;
	cin >> userInput;

	// See if item is in the inventory
	if (AlreadyInList(userInput)) {
		// Print item name and count if found
		for (auto produce : inventoryList) {
			if (produce.GetName() == userInput) {
				cout << endl;
				produce.PrintProduct();
			}
		}
	}
	else {
		// If not give an error code
		cout << endl << "That item was not sold." << endl;
	}

	// Clear input
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


void Inventory::CreateBackup() {
	// Creats a backup of the created Inventory with name and frequences
	// INIT output file stream
	ofstream outFS;

	// Open file
	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
	}
	// Write to file
	for (auto item : inventoryList) {
		outFS << item.GetName() << " " << item.GetCount() << endl;
	}

	// Close file
	outFS.close();
	// Message to user
	cout << "Backup Complete" << endl;
}