#include "FutureValue.h"
#include <cmath>

FutureValue::FutureValue(double investmentAmount, double annualInterestRate, double years)
{
	this->investmentAmount = investmentAmount;
	this->annualInterestRate = annualInterestRate;
	this->years = years;
}

double FutureValue::getAnnualInterestRate()
{
	return this->annualInterestRate;
}

double FutureValue::getInvestmentAmount()
{
	return this->investmentAmount;
}

double FutureValue::getYears()
{
	return this->years;
}

double FutureValue::getFutureValue()
{
	this->futureValue = this->investmentAmount * std::pow((1 + (this->annualInterestRate / 1200.0)), (this->years * 12));
	return this->futureValue;
}


