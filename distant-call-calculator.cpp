//============================================================================
// Name        : distant-call-calculator.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::tolower
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Time {
  int minute;
  int hour;
  string ampm;
};

Time getCallStartTime(string callStartTime)
{
	Time time;
	string error;
	string hourStr, minuteStr, a = "AM";
	hourStr.append(sizeof(char), callStartTime[0]);
	hourStr.append(sizeof(char), callStartTime[1]);
	minuteStr.append(sizeof(char), callStartTime[3]);
	minuteStr.append(sizeof(char), callStartTime[4]);
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
				time.hour = hour;
				time.minute = minute;
				time.ampm = a;
				return time;
			}
		}
	}catch(invalid_argument const &e)
	{
		error = "Bad input: " + callStartTime;
	}catch(out_of_range const &e)
	{
		error = "Bad input. Integer out of Range: " + callStartTime;
	}
	cout << error << endl;
	throw error;
}

double calculateAmountForFullWeekDay()
{
	double midDay = 10 * 60 * 0.4, others = 14 * 60 * 0.25;
	return midDay + others;
}

double calculateAmountForWeekDay(int from, int to)
{
	int s = 8 * 60, e = 18 * 60;
	if(from >= s && to <= e)
	{
		return (to - from) * 0.4;
	}else if((from < s && to < s) || (from > e && to > e))
	{
		return (to - from) * 0.25;
	}else if(from <= s && to >= e)
	{
		return ((s - from) * 0.25) + ((1080 - 480) * 0.4) + ((to - e) * 0.25);
	}else if(to <= e)
	{
		return ((to - s) * 0.4) + ((s - from) * 0.25);
	}else
	{
		return ((to - e) * 0.25) + ((e - from) * 0.4);
	}
}

double calculateAmountForWeekend(int from, int to)
{
	return (to - from) * 0.15;
}

int getDayOfWeek(string dayOfWeek)
{
	locale loc;
	transform(dayOfWeek.begin(), dayOfWeek.end(), dayOfWeek.begin(), ::tolower);
	string day = dayOfWeek;
	int currDay = -1;
	if(day == "m") currDay = 0;
	else if (day == "t") currDay = 1;
	else if (day == "w") currDay = 2;
	else if (day == "h") currDay = 3;
	else if (day == "f") currDay = 4;
	else if (day == "s") currDay = 5;
	else if (day == "u") currDay = 6;
	else
	{
		cout << "Invalid day of the week" << endl;
	}
	return currDay;
}

double calculateCallTime(string dayOfWeek, string callStartTime, int duration)
{
	double totalAmount = 0.0;
	if(duration == 0) return totalAmount;
	int currDay = getDayOfWeek(dayOfWeek);
	Time time = getCallStartTime(callStartTime);
	if(currDay != -1)
	{
		int startTimeInMins = time.hour * 60 + time.minute;
		int startDuration = startTimeInMins, endDuration = startTimeInMins + duration, minutesInADay = 24 * 60, endOfDay = minutesInADay;
		for(int i = 0; startDuration < endDuration; i++)
		{
			int diff = i * minutesInADay;
			if(endDuration < endOfDay)
			{
				endOfDay = endDuration;
			}
			if(currDay <= 4)
			{
				totalAmount += calculateAmountForWeekDay(startDuration - diff, endOfDay - diff);
			}else
			{
				totalAmount += calculateAmountForWeekend(startDuration - diff, endOfDay - diff);
			}
			startDuration = endOfDay;
			endOfDay += minutesInADay;
			currDay = (currDay + 1) % 7;
		}
		return totalAmount;
	}
	return -1;
}

int main() {
	cout << "Please enter space separated dayOfWeek, callStartTime and duration of call." << endl;
	cout << "dayOfWeek must follow this format: Enter m for Monday, t for Tuesday, w for Wednesday, h for Thursday, f for Friday, s for Saturday and u for Sunday." << endl;
	cout << "callStartTime must be in HH:mm i.e. 24hr time. e.g. 2pm is 14:00, 4:30pm is 16:30 and 7:20am is 7:20" << endl;
	cout << "duration is an integer that represents the duration of the call in minutes" << endl;

	string dayOfWeek;
	while(cin >> dayOfWeek)
	{
		string callStartTime;
		cin >> callStartTime;
		int duration;
		cin >> duration;
		double amount = calculateCallTime(dayOfWeek, callStartTime, duration);
		cout << "Total Amount is $" << amount << endl; // prints
	}
	cout << " done " << endl;
	return 0;
}
