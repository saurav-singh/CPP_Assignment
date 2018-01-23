//Test Source File to Test all methods and Operator Overlading in Rational Class

#include<iostream>
#include"Rational.h"

using namespace std;

int main()
{

	//Testing Constructors
	Rational R1;
	Rational R2(2,5);
	Rational R3(3,5);
	cout << "\n[Constructors work] \n\n";
	
	//Testing Output Method
	cout << "R1: "; R1.output();
	cout << "R2: "; R2.output();
	cout << "R3: "; R3.output();
	cout << "\n[Output method work] \n\n";

	//Testing Input Method
	R1 = R1.input();
	cout << endl;
	R1.output();
	cout << "\n[Input method work] \n\n";

	//Testing Arithmetic Operator Overloadings
	R1 = R2 + R3;
	R1.output();
	cout << "\n[Addition Operator work] \n\n";

	R1 = R2 - R3;
	R1.output();
	cout << "\n[Subtraction Operator work] \n\n";

	R1 = R2 * R3;
	R1.output();
	cout << "\n[Multiplication Operator work] \n\n";

	R1 = R2 / R3;
	R1.output();
	cout << "\n[Division Operator work] \n\n";

	R1 = R2 ^ 3;
	R1.output();
	cout << "\n[Exponential Operator work] \n\n";

	//Testing Input Operator Overloading;
	cout << "\nEnter a rational number in the fomat \"n/d\": ";
	cin >> R1;
	cout << "You Entered: " << R1;

	cout << "\n[<< / >> Operator work] \n\n";

	cout << "\nALL Testing Done! Program  Works.\n";

	return 0;
}