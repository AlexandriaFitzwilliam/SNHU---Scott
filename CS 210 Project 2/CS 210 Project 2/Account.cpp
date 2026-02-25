#include "Account.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

//CREATE Account getUserInput method :
void Account::getUserInput() {
	double userInput;

	//	DISPLAY to screen request for initial investment amount.
	cout << endl << "Initial Investment Amount: ";
	userInput = t_validUserInput();
	cout << endl;
	//	CALL validUserInput function.
	//	Call setInitialInvestment function.
	t_setInitialInvestment(userInput);

	//	DISPLAY to screen request for monthly deposit amount.
	cout << "Monthly Deposit: ";
	userInput = t_validUserInput();
	cout << endl;
	//	CALL validUserInput function.
	//	Call setMonthlyDeposit function.
	t_setMonthlyDeposit(userInput);

	//	DISPLAY to screen request for annual interst amount.
	cout << "Annual Interest: ";
	userInput = t_validUserInput();
	cout << endl;
	//	CALL validUserInput function.
	//	CALL setAnnualInterest function.
	t_setAnnualInterest(userInput);

	//	DISPLAY to screen request for number of years amount.
	cout << "Number of Years: ";
	userInput = t_validUserInput();
	cout << endl;
	//	CALL validUserInput function.
	//	CALL setNumberOfYears function.
	t_setNumberOfYears(userInput);

	// SET current balance to inital investment
	t_setCurrentBalance(t_getInitialInvestment());

}


//CREATE Account printUserInput method :
void Account::printUserInput() {
	cout << "*******************************************" << endl;
	cout << "********** Account Information ************" << endl;
	//	DISPLAY to screen Initial Investment Amount.
	cout << "Initial Investment Amount: $" << fixed << setprecision(2) << t_getInitialInvestment() << endl;
	//	DISPLAY to screen Monthly Deposit.
	cout << "Monthly Deposit: $" << t_getMonthlyDeposit() << fixed << setprecision(2) << endl;
	//	DISPLAY to screen Annual Interest.
	cout << "Annual Interest: " << t_getAnnualInterest() << fixed << setprecision(2) << "%" << endl;
	//	DISPLAY to screen Number of Years.
	cout << "Number of Years: " << int(t_getNumberOfYears()) << " Years" << endl;
	// DISPLAY Current Balance
	cout << "Current Balance: $" << fixed << setprecision(2) << t_getCurrentBalance() << endl << endl;

}


//CREATE Account printNoMonthlyDeposits method :
void Account::printNoMonthlyDeposits() {
	//	DEFINE integer current year variable with initial value of 1.
	int currentYear = 1;

	// DISPLAY Data for user
	cout << endl << "****************************************************************" << endl;
	cout << "*** Balance and Interest Without Additional Monthly Deposits ***" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "* Year        Year End Balance        Year End Earned Interest *" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//	WHILE current year is less than or equal to Account’s number of years :
	while (currentYear <= m_numberOfYears) {
		//	Call calculateYearEndBalance with depositAmount equal to 0.
		//	DISPLAY to screen.
		cout << "     " << currentYear << "      ";
		t_calculateYearEndBalance(0);
		//	Add one to current year.
		currentYear += 1;
	}
}


//CREATE Account PrintYesMonthlyDeposit method :
void Account::printYesMonthlyDeposits() {
	//	DEFINE integer current year variable with initial value of 1.
	int currentYear = 1;

	// DISPLAY Data for user
	cout << endl << "****************************************************************" << endl;
	cout << "***   Balance and Interest With Additional Monthly Deposits  ***" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "* Year        Year End Balance        Year End Earned Interest *" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//	WHILE current year is less than or equal to Account’s number of years :
	while (currentYear <= m_numberOfYears) {
		//	Call calculateYearEndBalance with depositAmount equal to 0.
		//	DISPLAY to screen.
		cout << "     " << currentYear << "      ";
		t_calculateYearEndBalance(t_getMonthlyDeposit());
		//	Add one to current year.
		currentYear += 1;
	}
}


//CREATE Account CalulateYearEndBalance method :
void Account::t_calculateYearEndBalance(double depositAmount) {
//	Takes in one variable, double DepositAmount.
//	SET MonthlyInterestAmount as InterestAmount / 100 / 12.
	double monthlyInterest = t_getAnnualInterest() / 100 / 12;
//	DEFINE integer current month variable with initial value of 1.
	int currentMonth = 1;
//	DEFINE double variable for YearlyInterestAmount with initial value of 0.
	double yearlyInterestAmount = 0;
//	DEFINE double variable for MonthlyInterestAmount with initial value of 0.
	double monthlyInterestAmount = 0;

//	WHILE current month variable is less than or equal to 12:
	while (currentMonth <= 12) {
		//		CALCULATE MonthlyInterestAmount.
//		(CurrentBalance + DepositedAmount) * MonthlyInterstAmount)
		monthlyInterestAmount = (t_getCurrentBalance() + depositAmount) * monthlyInterest;
//		ADD MonthlyInterestAmount to YearlyInterestAmount.
		yearlyInterestAmount += monthlyInterestAmount;
//		ADD 1 to current month variable.
		currentMonth += 1;
//		SET CurrentBalance equal to CurrentBalance + monthlyInterestAmount + (MonthlyDeposit).
		t_setCurrentBalance(t_getCurrentBalance() + monthlyInterestAmount + depositAmount);
	}

	//FIXME: STILL NEED TO FORMAT
	cout << setw(15) << "$" << t_getCurrentBalance();
	cout << setw(20) << "$" << yearlyInterestAmount << endl;
	
}


//CREATE Account ValidUserInput method :
double Account::t_validUserInput() {
	//DEFINE double UserInput variable with initial value of - 1.
	double userInput = -1;

	//WHILE UserInput is less than or equal to 0 :
	while (!(cin >> userInput) || (userInput <= 0)) {
		//	TRY capture user input.
		//	IF UserInput is equal or less than 0 :
		if (!cin) {
			//	DISPLAY to screen error message not a valid number.
			cout << "Sorry, that is not a valid number." << endl;
		}
		//	ELSE :
		else {
			//	DISPLAY to screen error message user cannot enter a zero or negative number.
			cout << "Sorry, you cannot enter zero or a negative number" << endl;
		}

		// Reset user input
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//	DISPLAY to screen prompt for new entry from user.
		cout << "Please enter a positive number: ";
	}

	//	Return UserInput.
	return userInput;
}


//CREATE Account SetInitialInvestment method :
void Account::t_setInitialInvestment(double initialInvestment) {
	//Takes in one argument, double variable for Investment Amount.
	//Sets Account’s InitalInvestment variable equal to argument.
	m_initialInvestment = initialInvestment;
}


//CREATE Account SetMonthlyDeposit method :
void Account::t_setMonthlyDeposit(double monthlyDeposit) {
	//Takes in one argument, double variable for Monthly Deposit.
	//Sets Account’s MonthlyDeposit variable equal to argument.
	m_monthlyDeposit = monthlyDeposit;
}


//CREATE Account SetAnnualInterest method :
void Account::t_setAnnualInterest(double annualInterest) {
	//Takes in one argument, double variable for Annual Interest.
	//Sets Account’s AnnualInterest variable equal to argument.
	m_annualInterest = annualInterest;
}


//CREATE Account SetNumberOfYears method :
void Account::t_setNumberOfYears(double numberOfYears) {
	//Takes in one argument, double variable for Number of Years.
	//Sets Account’s NumberOfYears variable equal to argument.
	m_numberOfYears = numberOfYears;
}


//CREATE Account SetCurrentBalance method :
void Account::t_setCurrentBalance(double currentBalance) {
	//Takes in one argument, double variable for Current Balance.
	//Sets Account’s CurrentBalance variable equal to argument.
	m_currentBalance = currentBalance;
}


//CREATE Account GetInitalInvestment method :
double Account::t_getInitialInvestment() {
	//Returns InitialInvestment variable.
	return m_initialInvestment;
}


//CREATE Account GetMonthlyDeposit method :
double Account::t_getMonthlyDeposit() {
	//Returns MonthlyDeposit variable.
	return m_monthlyDeposit;
}


//CREATE Account GetAnnualInterst method :
double Account::t_getAnnualInterest() {
	//Returns AnnualInterst variable.
	return m_annualInterest;
}


//CREATE Account GetNumberOfYears method :
double Account::t_getNumberOfYears() {
	//Returns NumberOfYears variable.
	return m_numberOfYears;
}


//CREATE Account GetCurrentBalance method :
double Account::t_getCurrentBalance() {
	//Returns CurrentBalance variable.
	return m_currentBalance;
}