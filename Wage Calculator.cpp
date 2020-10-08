// Wage Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
class Person {
private:
	std::string m_sName;
	double m_dPaidHourly;
	int m_iHowManyHoursWorkedWeekly;
public:
	//Template / prototypes
	Person(std::string sName, double dPaidHourly, int iHowManyHoursWorkedWeekly);
	std::string GetName();
	double CalculateWeeklyWage();
	double CalculateTaxToPayPerYear(double dHigherRate, double dLowerRate);
	double CalculateEarnedPerMonth();
	double CalculateHomeTake(double dHigherRate, double dLowerRate);

};
Person::Person(std::string sName, double dPaidHourly, int iHowManyHoursWorkedWeekly)
	:m_sName(sName), m_dPaidHourly(dPaidHourly), m_iHowManyHoursWorkedWeekly(iHowManyHoursWorkedWeekly)
{

}
std::string Person::GetName() {
	return m_sName;
}
double Person:: CalculateWeeklyWage() {
	return m_dPaidHourly * m_iHowManyHoursWorkedWeekly;
}
double Person::CalculateTaxToPayPerYear(double dHigherRate, double dLowerRate) {
	double dWeeklyWage = CalculateWeeklyWage();
	if ((dWeeklyWage * 52) > 25000)
	{
		return dWeeklyWage * dHigherRate;
	}
	else
	{
		return dWeeklyWage * dLowerRate;
	}
}
double Person::CalculateEarnedPerMonth() {
	return CalculateWeeklyWage() * 4;
}
double Person::CalculateHomeTake(double dHigherRate, double dLowerRate) {
	return (CalculateWeeklyWage() * 52) - CalculateTaxToPayPerYear(dHigherRate, dLowerRate) - CalculateTaxToPayPerYear(dHigherRate, dLowerRate);
}
class TaxCalculator {
private:
	std::vector<Person> m_objPeople;
public:
	void AddPersonToTaxCalculator(Person& objPerson);
	void DisplayUserInformation(double dHigherRate, double dLowerRate);
};
void TaxCalculator::AddPersonToTaxCalculator(Person& objPerson) {
	m_objPeople.push_back(objPerson);
}
void TaxCalculator::DisplayUserInformation(double dHigherRate, double dLowerRate) {
	for (Person& objPerson : m_objPeople) {
		std::cout << "----" << std::endl;
		std::cout << objPerson.GetName() << " gets " << char(156) << objPerson.CalculateWeeklyWage() << " a week." << std::endl;
		std::cout << "They earn " << char(156) << objPerson.CalculateEarnedPerMonth() << " per month." << std::endl;
		std::cout << "The tax they have to pay is " << char(156) << objPerson.CalculateTaxToPayPerYear(dHigherRate, dLowerRate) << " a year." << std::endl;
		std::cout << "The amount they will take home is " << char(156) << objPerson.CalculateHomeTake(dHigherRate, dLowerRate) << std::endl;
	}
	std::cout << "----" << std::endl;
}
int main()
{
	//Declaring the tax rates for the TaxCalculator
	const double dHigherRate = 0.25;
	const double dLowerRate = 0.15;
	//Initalizing three instances of "Person" using the three argument constructor
	Person objPerson1("George Bradley", 9.30, 72); 
	Person objPerson2("Sean Shearing", 10.00, 92);
	Person objPerson3("Jason Hill", 17.00, 89);

	TaxCalculator objTaxCalculator;

	objTaxCalculator.AddPersonToTaxCalculator(objPerson1);
	objTaxCalculator.AddPersonToTaxCalculator(objPerson2);
	objTaxCalculator.AddPersonToTaxCalculator(objPerson3);

	objTaxCalculator.DisplayUserInformation(dHigherRate, dLowerRate);
}


