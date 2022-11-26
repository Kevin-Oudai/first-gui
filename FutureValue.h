#pragma once
class FutureValue
{
public:
	FutureValue(double, double, double);
	double getAnnualInterestRate();
	double getInvestmentAmount();
	double getYears();
	double getFutureValue();

private:
	double investmentAmount;
	double annualInterestRate;
	double years;
	double futureValue;
};

