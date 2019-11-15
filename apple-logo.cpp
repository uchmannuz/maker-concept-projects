//============================================================================
// Name        : apple-logo.cpp
// Author      : Uchenna Nwanyanwu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void printItem (int count, string item)
{
	while(count-- > 0)
	{
		cout << item;
	}
}

void endLine()
{
	int time = 1;
	cout << endl;
	this_thread::sleep_for (std::chrono::seconds(time));
}

void printMiddle(int count, string at, string colon)
{
	while(count-- > 0)
	{
		printItem(30, at);
		printItem(1, colon);
		endLine();
	}
}


int main()
{
	string space = " ", eight = "8", dot = ".",
			quote = "'", andStr = "&", at = "@",
			colon = ":", percent = "%", tick = "`",
			hash = "#", dquote = "\"";
	int spaceStart = 25, eightStart = 1;
	printItem(spaceStart, space);
	printItem(eightStart, eight);
	endLine();

	printItem(spaceStart - 2, space);
	printItem(1, dot);
	printItem(eightStart + 2, eight);
	endLine();

	printItem(spaceStart - 4, space);
	printItem(1, dot);
	printItem(eightStart + 3, eight);
	printItem(1, quote);
	endLine();

	printItem(spaceStart - 5, space);
	printItem(1, dot);
	printItem(eightStart + 3, eight);
	printItem(1, quote);
	endLine();

	printItem(spaceStart - 5, space);
	printItem(eightStart + 2, eight);
	printItem(1, quote);
	endLine();

	printItem(spaceStart - 5, space);
	printItem(eightStart, eight);
	printItem(1, quote);
	endLine();

	printItem(spaceStart - 19, space);
	printItem(1, dot);
	printItem(eightStart + 10, eight);
	printItem(1, dot);
	printItem(1, space);
	printItem(1, dot);
	printItem(11, eight);
	printItem(1, dot);
	endLine();

	printItem(spaceStart - 22, space);
	printItem(1, dot);
	printItem(31, eight);
	printItem(1, dot);
	endLine();

	printItem(1, space);
	printItem(1, dot);
	printItem(34, eight);
	printItem(1, dot);
	endLine();

	printItem(1, dot);
	printItem(33, andStr);
	printItem(1, quote);
	endLine();

	printItem(32, andStr);
	printItem(1, quote);
	endLine();

	printItem(31, andStr);
	printItem(1, quote);
	endLine();

	printMiddle(3, at, colon);
	printItem(31, percent);
	printItem(1, dot);
	endLine();

	printItem(32, percent);
	printItem(1, dot);
	endLine();

	printItem(1, tick);
	printItem(33, percent);
	printItem(1, dot);
	endLine();

	printItem(1, space);
	printItem(1, tick);
	printItem(35, percent);
	printItem(1, quote);
	endLine();

	printItem(2, space);
	printItem(1, tick);
	printItem(33, percent);
	printItem(1, quote);
	endLine();

	printItem(3, space);
	printItem(1, tick);
	printItem(31, percent);
	printItem(1, quote);
	endLine();

	printItem(5, space);
	printItem(1, tick);
	printItem(27, hash);
	printItem(1, quote);
	endLine();

	printItem(7, space);
	printItem(1, tick);
	printItem(23, hash);
	printItem(1, quote);
	endLine();

	printItem(9, space);
	printItem(1, tick);
	printItem(9, hash);
	printItem(2, quote);
	printItem(8, hash);
	printItem(1, quote);
	endLine();

	printItem(11, space);
	printItem(1, tick);
	printItem(6, dquote);
	printItem(1, quote);
	printItem(2, space);
	printItem(1, tick);
	printItem(5, dquote);
	printItem(1, quote);
	return 0;
}


//Prints

/**
                        8
                      .888
                    .8888'
                   .8888'
                   888'
                   8'
      .88888888888. .88888888888.
   .8888888888888888888888888888888.
 .8888888888888888888888888888888888.
.&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&'
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&'
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&'
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%.
`%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%.
 `00000000000000000000000000000000000'
  `000000000000000000000000000000000'
   `0000000000000000000000000000000'
     `###########################'
jgs    `#######################'
         `#########''########'
           `""""""'  `"""""'
**/
