//============================================================================
// Name        : mad-lib.cpp
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
	string firstOrLastName, yourName, food, number, adjective, color, animal;
	cout << "The first or last name of your instructor: \n";
	getline(cin, firstOrLastName);
	cout << "Your name: \n";
	getline(cin, yourName);
	cout << "A food: \n";
	getline(cin, food);


	int num = 0;
	while(num < 100 || num > 200)
	{
		cout << "A number between 100 and 120: \n";
		getline(cin, number);
		num = stoi(number);
	}
	cout << "An adjective: \n";
	getline(cin, adjective);
	cout << "A color: \n";
	getline(cin, color);
	cout << "An animal: \n";
	getline(cin, animal);

	printf("Dear Instructor %s, \n", firstOrLastName.c_str());
	printf("I am sorry that I am unable to turn in my homework at this time. First, I ate a rotten %s, \n", food.c_str());
	printf("which made me turn %s and extremely ill. I came down with a fever of %d. \n", color.c_str(), num);
	printf("Next, my %s pet %s must have smelled the remains of the %s on my \n", adjective.c_str(), animal.c_str(), food.c_str());
	printf("homework, because he ate it. I am currently rewriting my homework and hope you will accept it \n");
	printf("late. \n");
	printf("Sincerely, %s \n", yourName.c_str());

}

