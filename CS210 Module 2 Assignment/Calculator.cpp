/*
 * Calculator.cpp
 *
 *  Date: 1/18/26
 *  Author: Alexandria Scott
 */

#include <iostream>
using namespace std;

void main()
{
	char statement[100];
	double op1, op2;  // changed to double instead of int so that / will work correctly
	char operation;
	char answer = 'Y';  //Missing ; to end line and it had double quotes instead of single " vs '.
		while (answer == 'Y' || answer == 'y')     // Changed while loop to include capital and lower case y.
		{
			cout << "Enter expression" << endl;
			cin >> op1 >> operation >> op2; // op1 and op2 were swapped

			// added {} for each branch and changed other options to if else instead of just if
			if (operation == '+') {     // changed double quotes to single and removed ; 
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;  // changed >> into <<
			}
			else if (operation == '-') { //replaced ; with {
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; // changed >> into <<
			}
			else if (operation == '*') {
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;   // output statment said it was dividing but it should be multiplying, added ; to end line
			}
			else if (operation == '/') { // should not have been indented for this line and next
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
			}
			//added else statment to catch not implemented actions and tell user that function isn't available
			else {
				cout << "Sorry, I cannot do that action." << endl;
			}

			// I would normally add a while loop here to validate user is entering a valid response.
			// However, it is not apart of the rubric of program functions.
			cout << "Do you wish to evaluate another expression? (Y/N)" << endl; //added info for user
			cin >> answer;
			cout << endl; // added whitespace in window for user ease
		}

		cout << "Program Finished" << endl;     // added a goodbye statment to users

}