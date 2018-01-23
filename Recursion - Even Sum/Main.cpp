#include<iostream>

using namespace std;

//FUNCTION PROTOTYPE
int printEven(int n, int c = 1);


void main()
{
	//VARIABLE DECLARATION
	int n, c;

	//DO WHILE LOOP FOR USER INPUT AND COMPUTATION UNTIL USER INPUTS 0
	do
	{
		//PROMPT FOR 
		cout << "\n\nEnter a positve integer to compute or 0 to end: ";
		cin >> n;

		if (n > 0)
		{
			cout << "\nThe even numbers between 0 to " << n << " are:\n";
			c = printEven(n);
			cout << "\nNumber of event integers: " << c;
		}

		else
		{
			cout << "\n Please Enter a Positive integer!";
		}

	} while (n != 0);
	
	
}

int printEven(int n, int c)
{

	//FOR BASE CASE
	if (n == 0)
	{
		cout << n;
		return c;
	}

	//FOR POSITIVE INPUT
	else
	{
		//FOR EVENT INPUT
		if (n % 2 == 0)
		{
			cout << n << ", ";
			return printEven(n - 2, ++c);
		}

		//FOR ODD INPUT
		else return printEven(n - 1, c);
	}
}



