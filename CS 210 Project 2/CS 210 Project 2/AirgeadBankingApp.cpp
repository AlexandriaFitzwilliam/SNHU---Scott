/*
* Method Name: AirgeadBankingApp
*
*  Author: Alexandria Scott
*  Creation Date: 2/8/2026
*
*  App that allows users to define an inital investment, monthly deposits, annual interest,
*  and number of years. Then will caluclate yearly interest and end of year balances with those values.
*  Shows both what happens with no monthly deposits, and with the user defined monthly deposit.
*/

#include <vector>
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;


//DEFINE function WantToContinue :
bool wantToContinue() {
//DEFINE vector for valid yes responses.
	vector<string> yesResponses = { "Yes", "yes", "Y", "y" };
//DEFINE vector for valid no responses.
	vector<string> noResponses = { "No", "no", "N", "n" };
//DEFINE userInput
	string userInput;

//WHILE user input is not valid :
	while (true) {
		//	DISPLAYS to screen question of if user wants to continue.
		cout << endl << "Would you like to try again? (Y/N)" << endl;
		//	CAPTURE user input.
		cin >> userInput;
		//	IF user input is Yes, yes, Y, or y :
		if (userInput == "Yes" || userInput == "yes" || userInput == "Y" || userInput == "y") {
			//	Return true.
			return true;
		}
		//	ELSE IF user input is No, no, N, or n :
		else if (userInput == "No" || userInput == "no" || userInput == "N" || userInput == "n") {
			//	Return false.
			return false;
		}
		//	ELSE :
		else {
			//	DISPLAY to screen error message.
			cout << "Sorry, that is not a valid response." << endl;
		}

	}

}


//Main function :
int main() {
	//	DEFINE Boolean variable for user wants to continue as true.
	bool keepGoing = true;
	//	DEFINE new Account variable.
	Account currentAccount;
	
	// Welcome message
	cout << endl << "****************************************************************" << endl;
	cout << "***              Welcome to Airgead Banking App.             ***" << endl;
	cout << "****************************************************************" << endl;

	//	LOOP WHILE user wants to calculate variable is true.
	while (keepGoing) {
//		CALL GetUserInput function.
		currentAccount.getUserInput();
//		CALL PrintUserInput function.
		currentAccount.printUserInput();
//		CALCULATE and DISPLAY balance without additional monthly deposits.
		currentAccount.printNoMonthlyDeposits();
//		CALCULATE and DISPLAY balance with additional monthly deposits.
		currentAccount.printYesMonthlyDeposits();

//		CALL WantToContinue function.
//		IF call is false:
//			SET user wants to continue variable to false.
//		ELSE :
//			Calculate another.
		keepGoing = wantToContinue();

	}

	// Goodbye message.
	cout << endl << "Goodbye" << endl;
}
