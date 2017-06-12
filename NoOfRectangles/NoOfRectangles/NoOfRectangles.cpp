// NoOfRectangles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>

int NoOfFactors(int n)
{
	int limi = floor(sqrt(n));
	int noOfFactors = 0;
	for (int i = 1; i <= limi; ++i)
	{
		if (n%i == 0)
			noOfFactors++;
	}

	return noOfFactors;
}

int main()
{
	int t;
	std::cin >> t;
	int count = 0;
	for (int i = 1; i <= t; ++i)
	{
		count = count + NoOfFactors(i);
	}
	std::cout << count << std::endl;
    return 0;
}

