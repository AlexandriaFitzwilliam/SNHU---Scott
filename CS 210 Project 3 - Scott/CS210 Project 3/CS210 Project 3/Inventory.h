#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Produce.h"
using namespace std;

#pragma once
class Inventory
{
public:
	// Create inventory using file
	Inventory(string txtFile);
	// Add produce item to vector
	void AddProduce(string itemName);
	void PrintInventoryList();
	void PrintInventoryHistogrm();
	void SearchInventory();
	void CreateBackup();

private:
	// Vector of produce items
	vector<Produce> inventoryList{};
	// Check if produce item is already in list
	bool AlreadyInList(string newName);
	// Add 1 to count to produce item
	void PlusOneToCount(string produceName);

};

