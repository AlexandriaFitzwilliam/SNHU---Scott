/*
Method name: Module5.cpp

Author: Alexandria Scott
Creation Date: 2/8/2026

Reads in a txt file with cities and temperatures, converts them to C, 
then creates a new file with updated temps.

*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// create a class to hold the info for a city
class City {
	public:
		void SetName(string cityName);
		void SetTemps(int cityFTemp);
		void Print();
		string name;
		int fTemp;
		double cTemp;
};

// Sets the city name.
void City::SetName(string cityName) {
	name = cityName;
}

// Sets the city F temp to given int, then converts and saves to C as well
void City::SetTemps(int cityFTemp) {
	fTemp = cityFTemp;

	cTemp = ((double)cityFTemp - 32) * ((double)5 / (double)9);
}

// Prints the city name and F temp.
void City::Print() {
	cout << name << " " << cTemp << endl;
}


int main() {
	// Input file stream
	ifstream inFS; // Input file stream
	ofstream outFS; // Output file stream
	string cityName;
	int fTemp;
	City newCity;
	vector<City> cities;


	
	// Open file
	inFS.open("FahrenheitTemperature.txt");

	// Error message if file is not open, then shuts down program.
	if (!inFS.is_open()) {
		cout << "Could not open file FahrenheitTemperature.txt." << endl;
		return 1;
	}

	// Loop through file until completed
	// Reads and assigns to variables in this lines, which can be interacted with during the loop
	while (inFS >> cityName >> fTemp) {

		newCity.SetName(cityName);
		newCity.SetTemps(fTemp);
		//newCity.Print();

		// Add new city to vector
		cities.push_back(newCity);

	}

	// Close the reading in file
	inFS.close();

	// Open new file
	outFS.open("CelsiusTemperature.txt");
	// Error message if file is not open, then shuts down program.
	if (!outFS.is_open()) {
		cout << "Could not open file CelsiusTemperature.txt." << endl;
		return 1;
	}


	// Loop through cities list to add to new file
	for (auto city : cities) {
		outFS << city.name << " " << city.cTemp << endl;
	}

	//Close output file
	outFS.close();

}