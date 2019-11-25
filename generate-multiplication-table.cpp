//============================================================================
// Name        : generate-multiplication-table.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Multiplication Table in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void accept(long long num, int count)
{
	int level = 1;
	cout << "********************************* " << num << " Multiplication Table *********************************" << endl;
	while(level <= count)
	{
		long long product = num * level;
		cout << num << " x " << level << " = " << product << endl;
		level++;
	}
	cout << "*******************************************************************************************************" << endl;
}

int main() {
	string input;
	getline(cin, input);
	stringstream check1(input);
	string token;

	while(getline(check1, token, ' '))
	{
		try
		{
			long long i = stoll(token);
			accept(i, 20);
		}catch(invalid_argument const &e)
		{
			cout << "Bad input: " << token << endl;
		}catch(out_of_range const &e)
		{
			cout << "Bad input. Integer out of Range: " << token << endl;
		}
	}
	return 0;
}
