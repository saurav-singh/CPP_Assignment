#ifndef Money_H
#define Money_H

#include<string>

using namespace std;

class Money
{

private:
	unsigned int cent_;

public:
	//Constructor
	Money(int dollar = 0, int cent = 0);

	//Mutator
	void addCent(int new_cent);
	void removeCent(int new_cent);
	void addDollar(int new_dollar);
	void removeDollar(int new_dollar);

	//Inpsector
	int getCent() const;

	//Facilitator
	string textOutput();
	int calculateDollar(int total_cent) const;
	int remainingCent(int total_cent) const;
	int totalCent(int dollar, int cent) const;

};

//Operator Overloading boolean
bool operator<(Money m1, Money m2);
bool operator<=(Money m1, Money m2);
bool operator>(Money m1, Money m2);
bool operator>=(Money m1, Money m2);
bool operator==(Money m1, Money m2);
bool operator!=(Money m1, Money m2);

//Operator Overloading Addition
Money operator+(Money m1, Money m2);

//Operator Overloading Subtraction
Money operator-(Money m1, Money m2);

//Operator Overloading Input
istream &operator>>(istream& in, Money &money);

//Operator Overloading Output
ostream &operator<<(ostream& out, Money &money);
#endif