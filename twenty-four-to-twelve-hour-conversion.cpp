//============================================================================
// Name        : twenty-four-to-twelve-hour-conversion.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;



int main() {
	cout << "Please enter 24-hour time in HH:mm format. e.g. 08:22, 14:09 etc." << endl;
	string input;
	getline(cin, input);
	stringstream check1(input);
	string token;

	//To strip whitespaces
	while(getline(check1, token, ' '))
	{
		if(!token.empty())
		{
			break;
		}
	}

	if(!token.empty() && token.size() == 6)
	{
		string hourStr, minuteStr, a = "AM";
		hourStr.append(sizeof(char), token[0]);
		hourStr.append(sizeof(char), token[1]);
		minuteStr.append(sizeof(char), token[3]);
		minuteStr.append(sizeof(char), token[4]);
		try
		{
			int hour = stoi(hourStr), minute = stoi(minuteStr);
			if(hour > 23 || hour < 0)
			{
				cout << "Invalid Hour" << endl;
			}else
			{
				if(minute > 59 || minute < 0)
				{
					cout << "Invalid Minute" << endl;
				}else
				{
					if(hour == 0)
					{
						hour = 12;
					}else if(hour >=12 && hour <= 23)
					{
						if(hour != 12)
						{
							hour = hour % 12;
						}
						a = "PM";
					}
					cout << "Time in 12-hour notation = " << hour << ":" << minute << " " << a << endl;
				}
			}
		}catch(invalid_argument const &e)
		{
			cout << "Bad input: " << token << endl;
		}catch(out_of_range const &e)
		{
			cout << "Bad input. Integer out of Range: " << token << endl;
		}
	}else
	{
		cout << "Bad Input" << endl;
	}
	return 0;
}
