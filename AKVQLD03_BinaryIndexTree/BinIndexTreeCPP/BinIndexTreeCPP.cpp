// BinIndexTreeCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "array"
#include "iostream"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void Add(int pos, int val, vector<int>& arr, int n)
{
	while(pos < n)
	{
		arr[pos] += val;
		pos = pos + (pos & (-pos));
	}
}

int Sum (int pos,vector<int>& arr, int n)
{
	int sum = 0;
	while(pos >=1)
	{
		sum += arr[pos];
		pos = pos - (pos & (-pos));
	}

	return sum;
}

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int n;
	std::cin >> n;
	int q;
	std::cin >> q;
	const int l = n + 1;
	vector<int> arr(l);

	while(q--)
	{
		string op; 
		std::cin >> op;

		if(op == "add")
		{
			int pos;
			std::cin >> pos;
			pos;
			int val;
			std::cin >> val;
			Add(pos, val, arr, l);
		}
		else
		{
			int pos1;
			std::cin >> pos1;
			pos1--;
			int pos2;
			std::cin >> pos2;
			std::cout << (Sum(pos2, arr, l) - Sum(pos1, arr, l)) << std::endl;
		}
	}
#if _DEBUG
	string xx;
	std::cin >> xx;
#endif

    return 0;
}

