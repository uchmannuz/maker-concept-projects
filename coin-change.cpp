//============================================================================
// Name        : coin-change.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Source: https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
	vector<int> array[V+1];
    int table[V+1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
              	  //array[i].push_back();
          }
    }
    return table[V];
}

// Driver program to test above function
int main()
{
	int amount = 0;
	while(amount < 1 || amount > 99)
	{
		cout << "Enter amount between 1 and 99: \n" ;
		cin >> amount;
	}

    int coins[] =  {25, 10, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    cout << "Minimum coins required is "
         << minCoins(coins, m, amount);
    return 0;
}
