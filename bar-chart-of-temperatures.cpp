//============================================================================
// Name        : bar-chart-of-temperatures.cpp
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

void drawHorizontalBar(int width, string value)
{
	while(width-- > 0)
	{
		cout << value;
	}
}

void drawNumber(int width, int value)
{
	while(width-- > 0)
	{
		cout << value;
	}
}

void draw(int temperatures[], int n)
{
	if(n == 0)
	{
		cout << "Temperature array is empty" << endl;
	}else
	{
		int max = temperatures[0];
		for(int i = 1; i < n; i++)
		{
			if(max < temperatures[i])
			{
				max = temperatures[i];
			}
		}
		bool horizontalBar[n];
		for(int i = 0; i < n; i++)
		{
			horizontalBar[i] = false;
		}
		int level = max, spaceBetweenBars = 4, barWidth = 4, lineDot = 1, barInternalSpace = barWidth - (2 * lineDot);

		drawHorizontalBar(1, " ");
		drawHorizontalBar(1, "^");
		cout << endl;
		drawHorizontalBar(1, " ");
		drawHorizontalBar(1, "|");
		cout << endl;

//		int numWidth = 0, l = max;
//		while(l > 0)
//		{
//			++numWidth;
//			l /= 10;
//		}

		while(level > 0)
		{
			drawNumber(1, level);
			drawHorizontalBar(1, "|");

			for(int j = 0; j < n; j++)
			{
				drawHorizontalBar(spaceBetweenBars, " ");
				if(!horizontalBar[j] && temperatures[j] == level)
				{
					horizontalBar[j] = true;
					--temperatures[j];
					drawHorizontalBar(barWidth, "*");
				}else if (temperatures[j] == level)
				{
					drawHorizontalBar(lineDot, "*");
					drawHorizontalBar(barInternalSpace, " ");
					drawHorizontalBar(lineDot, "*");
					--temperatures[j];
				}else
				{
					drawHorizontalBar(barWidth, " ");
				}
			}
			cout << endl;
			--level;
		}
		int len = (n * spaceBetweenBars) + (n * barWidth) + 2;
		drawHorizontalBar(2, " ");
		for(int j = 0; j < len; j++)
		{
			cout << "-";
		}
		drawHorizontalBar(1, ">");
		cout << endl;
	}
}
int main() {
	cout << "********************** Kindly note that this program does not check for bad input.**********************" << endl;
	cout << "Enter the size of the Array: " << endl;
	int size;
	cin >> size;
	cout << "Enter " << size << " numbers, each separated by space: ";

	int temperatures[size];
    for (int i = 0; i < size; ++i)
    {
        cin >> temperatures[i];
    }
	draw(temperatures, size);
	return 0;
}
