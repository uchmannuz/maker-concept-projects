//============================================================================
// Name        : sentence-summary.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Sentence summary
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
	bool foundWordCharacter = false, foundFirstWord = false;
	//Get character count
	for (auto x : input)
	{
		if(x == 13) continue;
		if(x == ' ' || x == '.' || x == ',' || x == '!')
		{
			if(!foundWordCharacter && foundFirstWord)
			{
				++wordCount;
			}
			foundWordCharacter = true;
		}else
		{
			foundWordCharacter = false;
			foundFirstWord = true;
		}
		++characterSummary[(int)x];
	}
	if(!foundWordCharacter && foundFirstWord)
	{
		++wordCount;
	}
	cout << "Total Number of Words = " << wordCount << endl;
	for(int i = 0; i < size; i++)
	{
		if(i != 13 && characterSummary[i] > 0)
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
