#include "Money.h"
#include <string>
#include <sstream>

using namespace std;

//Constructor Definition
Money::Money(int dollar, int cent)
{
	cent_ = totalCent(dollar, cent);
}	

//Mutator Definition
void Money::addCent(int new_cent)
{
	cent_ += new_cent;
}

void Money::removeCent(int new_cent)
{
	cent_ -= new_cent;
}

void Money::addDollar(int new_dollar)
{
	cent_ += new_dollar * 100;
}

void Money::removeDollar(int new_dollar)
{
	cent_ -= new_dollar * 100;
}

//Inspector Definition
int Money::getCent() const
{
	return cent_;
}
//Facilitators 

//Method to return string so that money object can be displayed in $dd.cc format
string Money::textOutput()
{
	ostringstream os;
	os << "Total Amount: $" << calculateDollar(cent_) << '.' << remainingCent(cent_);
	return os.str();
}

//Method to Count total cents and takes dollar and cent as parameter 
int Money::totalCent(int dollar, int cent) const
{
	return  ((dollar * 100) + cent);	
}

//Method to Count total dollars and takes total cent as parameter
int Money::calculateDollar(int total_cent) const
{
	unsigned int dollar;
	dollar = total_cent / 100;
	return dollar;
}

//Method to Count remaining cent and takes total cent as parameter
int Money::remainingCent(int total_cent) const
{
	unsigned int remaining_cent, dollar;
	dollar = total_cent / 100;
	remaining_cent = total_cent - (dollar * 100);
	return remaining_cent;
}


//Operator Overloading boolean
bool operator<(Money m1, Money m2)
{
	if (m1.getCent() < m2.getCent()) return true;
	else							 return false;		
}

bool operator<=(Money m1, Money m2)
{
	if (m1.getCent() <= m2.getCent()) return true;
	else		                      return false;
}

bool operator>(Money m1, Money m2)
{
	if (m1.getCent() > m2.getCent()) return true;
	else							 return false;
}

bool operator>=(Money m1, Money m2)
{
	if (m1.getCent() >= m2.getCent()) return true;
	else				              return false;
}

bool operator==(Money m1, Money m2)
{
	if (m1.getCent() == m2.getCent()) return true;
	else					          return false;
}

bool operator!=(Money m1, Money m2)
{
	if (m1.getCent() != m2.getCent()) return true;
	else							  return false;
}

//Operator Overloading Addition
Money operator+(Money m1, Money m2)
{
	int sum_cent = m1.getCent() + m2.getCent();
	Money m(0,sum_cent);
	return m;
}

//Operator Overloading Subtraction
Money operator-(Money m1, Money m2)
{
	int diff_cent = m1.getCent() - m2.getCent();
	Money m(0, diff_cent);
	return m;
}


//Operator Overloading Input
istream &operator >> (istream& in, Money& money)
{
	int dollar = 0, cent = 0;
	char sign1, sign2;
	in >> sign1 >> dollar >> sign2 >> cent;
	money.addDollar(dollar);
	money.addCent(cent);
	return in;
}

//Operator Overloadng Output
ostream &operator<<(ostream& out, Money &money)
{
	char dollar_sign = '$';
	char dot = '.';
	out << dollar_sign << money.calculateDollar(money.getCent()) << dot << money.remainingCent(money.getCent());
	return out;
}