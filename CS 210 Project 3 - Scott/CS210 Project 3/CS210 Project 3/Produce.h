#include <iostream>
#include <string>
#include <exception>
#include <limits>
using namespace std;

#pragma once
class Produce
{
	// Public class functions.
public:
	void SetName(string name);
	string GetName();
	void AddCount();
	int GetCount();
	Produce(); //default constructor: only used if there is an error
	Produce(string initName); //use this constructor
	void PrintProduct();

	// Private class functions.
private:
	string name;
	int count;

};

