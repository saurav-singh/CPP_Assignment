#include<vector>
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int vectorSum(vector <int> v);

void main()
{
	//Vector delcaration
	vector <int> v;

	//Populate vector with 20 random numbers between -100 and 100
	srand(time(NULL));

	for (int i = 0; i < 20; i++)
		v.push_back(rand() % 201 - 100);

	//Display vector
	cout << "\nRandomly Generated numbers in vector:\n";
	
	for (int i = 0; i < 20; i++)
		cout << v[i] << endl;
	

	//Calling vectorSum Function
	int sum = vectorSum(v);

	//Display sum of integers in vector
	cout << "\nSum = " << sum << endl;	

}

int vectorSum(vector <int> v)
{
	//BASE CASE
	if (v.size() == 1) return v[0];
	
	//ADD LAST ELEMENT TO THE SECOND LAST ELEMENT 
	//REMOVE LAST ELEMENT 
	//PERFORM RECURSION ON THE REMAINING VECTOR
	else
	{
		v[v.size() - 2] += v[v.size() - 1];
		v.pop_back();
		return vectorSum(v);
	}	

}