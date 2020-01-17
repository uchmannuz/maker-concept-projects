//============================================================================
// Name        : coin-change.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int amount = 0;
	while(amount < 1 || amount > 99)
	{
		cout << "Enter an integer between 1 and 99: \n" ;
		cin >> amount;
	}
	int initialAmount = amount;
    int coins[] =  {25, 10, 1}, quarter = 0, dime = 0, penny = 0;
    int index = 0;
    while(amount > 0)
    {
    	int temp = amount;
    	while((temp - coins[index]) >= 0)
    	{
    		temp -= coins[index];
    		if(index == 0) quarter++;
    		else if(index == 1) dime++;
    		else if(index == 2) penny++;
    	}
    	amount = temp;
    	++index;
    }

    cout << initialAmount << " cents can be give as ";
    if(quarter) cout << quarter << " quarter(s) ";
    if(dime) cout << dime << " dime(s) ";
    if(penny) cout << penny << " penny (pennies)\n";

    return 0;
}
