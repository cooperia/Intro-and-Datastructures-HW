//Author: Ian Cooper
//Date: 1/27/08
//Purpose: Converts U.S. Dollars to Euros.
//Source: Google.com (search Dollars to Euros).


#include <iostream>
using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	double number_of_dollars;
	double total_gold;

	cout <<"Enter the number of dollars you would like to exchange for Euros.\n";
	cout << "Then press enter.\n";
	cin >> number_of_dollars;

	total_gold = number_of_dollars * .67902492;

	cout <<number_of_dollars << " converted to Euros";
	cout << " gives you a total of " <<total_gold << " Euros.\n";

return 0;
}