//============================================================================
// Name        : sentence-summary.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void summary(string input)
{
	//Ascii has 256 characters
	int characterSummary[256];
	//Get array size
	int size = sizeof(characterSummary) / sizeof(characterSummary[0]);
	//Initialize characterSummary array
	for(int i = 0; i < size; i++)
	{
		characterSummary[i] = 0;
	}
	int wordCount = 0;
	bool foundCharacter = false;
	//Get character count
	for (auto x : input)
	{
		if(x == ' ' || x == '.' || x == ',' || x == '!')
		{
			if(!foundCharacter)
			{
				++wordCount;
			}
			foundCharacter = true;
		}else
		{
			foundCharacter = false;
		}
		++characterSummary[(int)x];
	}
	if(!foundCharacter)
	{
		++wordCount;
	}
	cout << "Total Number of Words = " << wordCount << endl;
	for(int i = 0; i < size; i++)
	{
		if(characterSummary[i] > 0)
		{
			char a = i;
			cout << a << " = " << characterSummary[i] << endl;
		}
	}
}

int main() {
	string sentence;
	getline(cin, sentence);
	if(sentence.size() == 0)
	{
		cout << "The supplied String is empty. Please supply a valid String" << endl;
	}else
	{
		summary(sentence);
	}
	return 0;
}
