/*
 *  Clock.cpp
 * 
 *  Request inital time from users. Then allows user to update current time through a simple menu,
 *  while displaying both 12 and 24 hour versions.
 *
 *  Date: 1/25/26
 *  Author: Alexandria Scott
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;


// function for displaying menu
void displayMenu()
{
	cout << "**************************" << endl;
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - Exit Program       *" << endl;
	cout << "**************************" << endl;
}


// function to display clocks. Takes in two vectors with three integers and one string for am or pm.
void displayClocks(vector<int> clock12, string AMPM, vector<int> clock24)
{
	cout << "***************************" << "    "; //Clock12 Top Box
	cout << "***************************" << endl; //Clock24 Top Box

	cout << "*      12-Hour Clock      *" << "    "; //Clock12 Header
	cout << "*      24-Hour Clock      *" << endl; //Clock12 Header

	cout << "*       ";							   //Clock12 Intro
	cout << setfill('0') << setw(2) << clock12[0] << ":"; //Clock12 Hours
	cout << setfill('0') << setw(2) << clock12[1] << ":"; //Clock12 Minutes
	cout << setfill('0') << setw(2) << clock12[2]; //Clock12 Seconds
	cout << " " << AMPM << "       *" << "    ";     //Clock12 AMPM and Ending

	cout << "*        ";							   //Clock24 Intro
	cout << setfill('0') << setw(2) << clock24[0] << ":"; //Clock24 Hours
	cout << setfill('0') << setw(2) << clock24[1] << ":"; //Clock24 Minutes
	cout << setfill('0') << setw(2) << clock24[2]; //Clock24 Seconds
	cout << "         *" << endl;     //Clock24 Ending

	cout << "***************************" << "    "; //Clock12 Bottom Box
	cout << "***************************" << endl; //Clock24 Bottom Box

}


// function to convert hours from 24 hour clock into 12 hour clock
pair<int, string> convertToClock12(vector<int> clock24) {
	//INIT variables for ampm and clock 12 hours
	int clock12Hours;
	string AMPM;

	// If the clock 24 hour is over 12
	if (clock24[0] > 12)
	{
		// use modelo to find the remainder and save as clock 12 hour
		clock12Hours = clock24[0] % 12;
		// assign ampm to pm
		AMPM = "PM";
	}
	else if (clock24[0] == 0)
	{
		clock12Hours = 12;
		AMPM = "AM";
	}
	else if (clock24[0] == 12)
	{
		clock12Hours = 12;
		AMPM = "PM";
	}
	else {
		// Else assign clock 24 hour as clock 12 hour
		clock12Hours = clock24[0];
		//assign ampm to am	
		AMPM = "AM";
	}

	//cout << "clock12Hours = " << clock12Hours << endl;
	//cout << "AMPM = " << AMPM << endl;
	return make_pair(clock12Hours, AMPM);
}


// check if number fed in is less than the second arguement
bool isValidNumber(int clockNum, int highestNum)
{
	bool isValid;

	if ((clockNum < highestNum) && (clockNum >= 0)) {
		isValid = true;
	}
	else {
		isValid = false;
	}

	return isValid;
}


vector<int> getInitalTime()
{
	// INIT vector to return clock info
	vector<int> clock24(3);
	bool isValid = false;


	cout << "Please use a 24 hour format to answer the following." << endl;
	// Get user input for original time
	while (!isValid) {
		cout << "What hour is it?" << endl;
		cin >> clock24.at(0);

		if (!isValidNumber(clock24.at(0), 24))
		{
			cout << "Sorry, the hour must be 1-23." << endl;
		}
		else {
			break;
		}
	}
	while (!isValid) {
		cout << "What is the minutes?" << endl;
		cin >> clock24.at(1);

		if (!isValidNumber(clock24.at(1), 60))
		{
			cout << "Sorry, the minute must be 0-59." << endl;
		}
		else {
			break;
		}
	}
	while (!isValid) {
		cout << "What is the seconds?" << endl;
		cin >> clock24.at(2);

		if (!isValidNumber(clock24.at(2), 60))
		{
			cout << "Sorry, the seconds must be 0-59." << endl;
		}
		else {
			break;
		}
	}

	return clock24;
}


//function to update once hours, min, and secs get too high
vector<int> updateAll(vector<int> clock)
{

	//start with seconds and go up
	if (!isValidNumber(clock.at(2), 60)) {
		clock.at(2) = 0;
		clock.at(1) += 1;
	}
	// checks minutes
	if (!isValidNumber(clock.at(1), 60)) {
		clock.at(1) = 0;
		clock.at(0) += 1;
	}
	// checks hours
	if (!isValidNumber(clock.at(0), 24)) {
		clock.at(0) = 0;
	}

	return clock;
}



void main()
{
	//INIT clock 12 vector
	vector<int> clock12(3);
	string AMPM = "AM";
	//INIT clock 24 vector
	vector<int> clock24(3);
	// INIT boolean variable for updating clock
	bool updatingClock = true;
	// INIT user input for menu
	int userInput;
	

	// Get user input for original time
	clock24 = getInitalTime();


	// Continue to loop until user exits
	while (updatingClock == true)
	{
		// Flowchart does not indicate clock should be displayed here, so the first time the program is run, there is no clock shown.
		// I would personally have moved the display clock to the beginning of the loop instead of the end. So users could see the time before
		// updating it.
		// Display Menu
		displayMenu();

		try {

			// Get user input
			cin >> userInput;

			// If add hour
			if (userInput == 1)
			{
				clock24.at(0) += 1;
			}
			// Else if add minute
			else if (userInput == 2)
			{
				clock24.at(1) += 1;
			}
			// Else if add second
			else if (userInput == 3)
			{
				clock24.at(2) += 1;
			}
			// Else if exit
			else if (userInput == 4)
			{
				updatingClock = false;
				break;
			}
			// Else
			else {
				// Add error message that this shouldn't be possible
				cout << "Sorry, that is not an option. Please pick again." << endl;
				continue;
			}

		}
		catch(...) {	//FIXME: NOT WORKING TO CATCH USER INPUTING NON INT NUMBERS. GETS CAUGHT IN INFINATE LOOP.
			cout << "Sorry, that is not an option. Please pick again." << endl;
		}

		// Checks if anything has gone above the 24 or 60 mark
		clock24 = updateAll(clock24);

		// Convert new time to clock12
		pair <int, string> result = convertToClock12(clock24);
		// Save updated time to clock12
		clock12[0] = result.first;
		clock12[1] = clock24[1];
		clock12[2] = clock24[2];
		AMPM = result.second;
		// Display Time
		displayClocks(clock12, AMPM, clock24);
	}

	cout << "GOODBYE" << endl;

}

