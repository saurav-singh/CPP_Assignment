#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include "Rational.h"


using namespace std;

//Constructor Implementation
Rational::Rational()
{
	p_ = 0;
	q_ = 0;
}

Rational::Rational(int N)
{
	p_ = N;
	q_ = 1;
}

Rational::Rational(int N, int M)
{
	if (M == 0)
		cout << "Denominator cannot be 0.";
	else
	{
		//Changes sign if denominator is negative
		if (M < 0)
		{
			N = N*(-1);
			M = M*(-1);
		}

		//Assigns the Value to attributes after cheking if num and denominators are same.
		if (N == M)
		{
			p_ = 1;
			q_ = 1;
		}
		else if (N*(-1) == M)
		{
			p_ = -1;
			q_ = 1;
		}
		else
		{
			p_ = N;
			q_ = M;
		}
	}

	//Converts the rational number to its simplest form
	simpleForm(p_, q_);
}

//Getter Methods Implementation
int Rational::getNumerator()
{
	return p_;
}

int Rational::getDenominator()
{
	return q_;
}

//Setter Methods Implementation
void Rational::setNumerator(int n)
{
	p_ = n;
}
void Rational::setDenominator(int d)
{
	q_ = d;
}

//Checks if two numbers are in simplest form or not.
bool simplestFormCheck(vector<int> factors, int a, int b)
{
	for (int i = 0; i < factors.size(); i++)
	{
		if (a % factors[i] == 0 && b % factors[i] == 0)
			return false;
	}

	return true;
}

//Changes two integers into their simplest form
void Rational::simpleForm(int &n, int &d)
{
	//Vairable Declaration
	int small;
	vector<int> factors;
	
	//Setup small as the smaller integer between two inputs
	if (n < d) small = n;
	else small = d;

	//Finds the list of common factors of the two integers
	for (int i = 2; i <= small; i++)
	{
		if (n % i == 0 && d % i == 0)
			factors.push_back(i);
	}

	//Loops until the inputs are at their simplest form
	while (!simplestFormCheck(factors, n, d))
	{
		for (int i = 0; i < factors.size(); i++)
		{
			if (n % factors[i] == 0 && d % factors[i] == 0)
			{
				n = n / factors[i];
				d = d / factors[i];
			}
		}
	}
	
}

	
//Input and Output Method Implementation
Rational Rational::input()
{
	//Variable Declaration
	string input, temp;
	int numerator, denominator, index;

	//User Input
	cout << "\nEnter a rational number in the fomat \"n/d\": ";
	cin >> input;

	//Finds positin of \ charter from input
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '/')
			index = i;
	}

	//Set numerator value (converts from string to int)
	for (int i = 0; i < index; i++)
	{
		temp += input[i];
	}		
	istringstream(temp) >> numerator;
	
	//Clear temp string
	temp = "";
	
	//Set denominator value (converts from string to int)
	for (int i = index+1; i < input.size(); i++)
	{
		temp += input[i];
	}
	istringstream(temp) >> denominator;
	
	//Create a Ratinoal object r with the user input values
	Rational r(numerator, denominator);

	//Return r
	return (r);

}

void Rational::output() const
{
	cout << p_;
	if (p_ != 0 && q_!= 1) {
		cout << "/" << q_;
	}
	cout << endl;
}

//Operator Overloading Implementations
Rational Rational::operator+(Rational r) const
{
	int N, D;

	//Adding two fractions by taking LCM of the two
	D = this->q_ * r.q_;
	N = (this->p_ * r.q_) + (this->q_ * r.p_);

	Rational R(N, D);
	return R;
}

Rational Rational::operator-(Rational r) const
{
	int N, D;

	//Subtracting two fractions by taking LCM of the two
	D = this->q_ * r.q_;
	N = (this->p_ * r.q_) - (this->q_ * r.p_); q_;

	Rational R(N, D);
	return R;
}

Rational Rational::operator*(Rational r) const
{
	int N = this->p_ * r.p_;
	int D = this->q_ * r.q_;
	Rational R(N, D);
	return R;
}

Rational Rational::operator/(Rational r) const
{
	int N = this->p_ * r.q_;
	int D = this->q_ * r.p_;
	Rational R(N, D);
	return R;
}

Rational Rational::operator^(int power) const
{
	int N = pow(this->p_, power);
	int D = pow(this->q_, power);
	Rational R(N, D);
	return R;
}

//Output operator Overload Implementation
ostream& operator<<(ostream& out, Rational& R) {
	
	out << R.getNumerator();
	if (R.getNumerator() != 0 && R.getDenominator() != 1) {
		out << "/" << R.getDenominator();
	}
	return out;
}

//Input operator Overload Implementation
 istream& operator>>(istream& in, Rational& R) 
 {
	 {

		 int n, d;
		 char sign;

		 in >> n >> sign >> d;
		 if (d != 0)
		 {
			 R.setNumerator(n);
			 R.setDenominator(d);
			 R.simpleForm(n, d);
		 }

		 return in;
	 }
 }
