//============================================================================
// Name        : data-encryption.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

char encrypt(char c, int strSpacing, int numSpacing)
{
	if(c >= 65 && c <= 90) //Uppercase
	{
		int value = ((c - 'A') + strSpacing) % 26;
		return (char) ('A' + value);
	}else if(c >= 97 && c <= 122) //Lowercase
	{
		int value = ((c - 'a') + strSpacing) % 26;
		return (char) ('a' + value);
	}else if(c >= 48 && c <= 57) //Numbers
	{
		int value = ((c - '0') + numSpacing) % 10;
		return (char) ('0' + value);
	}else //Others
	{
		return c;
	}
}

char decrypt(char c, int strSpacing, int numSpacing)
{
	if(c >= 65 && c <= 90) //Uppercase
	{
		int value = ((c - 'A') + (26 - strSpacing)) % 26;
		return (char) ('A' + value);
	}else if(c >= 97 && c <= 122) //Lowercase
	{
		int value = ((c - 'a') + (26 - strSpacing)) % 26;
		return (char) ('a' + value);
	}else if(c >= 48 && c <= 57) //Numbers
	{
		int value = ((c - '0') + (10 - numSpacing)) % 10;
		return (char) ('0' + value);
	}else //Others
	{
		return c;
	}
}

int main() {
	  std::string value, result, result2;
	  std::cout << "Enter String to Encrypt: ";
	  getline (std::cin, value);

	  for(int i = 0; i < value.length(); i++)
	  {
		  result.append(sizeof(char), encrypt(value[i], 20, 6));
	  }
	  cout << result << endl;
	  for(int i = 0; i < result.length(); i++)
	  {
		  result2.append(sizeof(char), decrypt(result[i], 20, 6));
	  }
	  cout << result2 << endl;
}
