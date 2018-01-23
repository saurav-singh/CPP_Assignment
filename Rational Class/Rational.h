#ifndef _RATIONAL_
#define _RATIONAL_

using namespace std;

class Rational
{

private:
	int p_;	//Numerator
	int q_;	//Denominator

public:
	//Constructors
	Rational();
	Rational(int N);
	Rational(int N, int M);

	//Getter Methods
	int getNumerator();
	int getDenominator();

	//Set Methods
	void setNumerator(int);
	void setDenominator(int);

	//Required Methods
	Rational input();
	void output() const;
	void simpleForm(int &n, int &d);

	//Arithmetic Operator Overloading as member functions
	Rational operator+(Rational) const;
	Rational operator-(Rational) const;
	Rational operator*(Rational) const;
	Rational operator/(Rational) const;
	Rational operator^(int) const;

	//Input and Output Operator Overloading as friend functions
	friend ostream &operator<<(ostream& out, Rational& R);
	friend istream &operator>> (istream & in, Rational& R);	

};

#endif 