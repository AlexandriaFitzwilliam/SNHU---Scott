#pragma once
//CREATE Account class :
class Account {
	//	DEFINE public data members :
public:
	//	Function getUserInput.
	void getUserInput();
	//	Function printUserInput.
	void printUserInput();
	//	Function printNoMonthlyDeposits.
	void printNoMonthlyDeposits();
	//	Function printYesMonthlyDeposits.
	void printYesMonthlyDeposits();

	//	DEFINE private data members : -- use m_ for naming variables and t_ for methods
private:
	//	Double initialInvestment initial value of - 1.
	double m_initialInvestment = -1;
	//	Double monthlyDeposit initial value of - 1.
	double m_monthlyDeposit = -1;
	//	Double annualInterest initial value of - 1.
	double m_annualInterest = -1;
	//	Double numberOfYears initial value of - 1.
	double m_numberOfYears = -1;
	//	Double currentBalance initial value of 0.
	double m_currentBalance = 0;
	//	Function calulateYearEndBalance.
	void t_calculateYearEndBalance(double depositAmount);
	//	Function validUserInput.
	double t_validUserInput();
	//	Function setInitialInvestment.
	void t_setInitialInvestment(double initialInvestment);
	//	Function setMonthlyDeposit.
	void t_setMonthlyDeposit(double monthlyDeposit);
	//	Function setAnnualInterest.
	void t_setAnnualInterest(double annualInterest);
	//	Function setNumberOfYears.
	void t_setNumberOfYears(double numberOfYears);
	//	Function setCurrentBalance.
	void t_setCurrentBalance(double moneyGrowth);
	//	Function getInitalInvestment.
	double t_getInitialInvestment();
	//	Function getMonthlyDeposit.
	double t_getMonthlyDeposit();
	//	Function getAnnualInterst.
	double t_getAnnualInterest();
	//	Function getNumberOfYears.
	double t_getNumberOfYears();
	//	Function getCurrentBalance.
	double t_getCurrentBalance();
};

