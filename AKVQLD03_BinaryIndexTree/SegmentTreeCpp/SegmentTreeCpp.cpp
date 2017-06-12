// SegmentTreeCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int ReadInt()
{
	int n;
	cin >> n;
	return n;
}

void Update(int pos, vector<int>& arr, int l ,int low, int high, int val, int root)
{
	
	if (pos < low || pos > high)
		return;

	arr[root] += val;
	if(low == high)
		return;
	

	int mid = (low + high) / 2;
	Update(pos, arr, l,low, mid, val, 2*root +1);

	Update(pos, arr, l, mid + 1, high, val, 2*root +2);

}

int Range(int pos1, int pos2, vector<int>& arr, int low, int high, int root)
{
	if (pos1 <= low && pos2 >= high)
		return arr[root];
	else if (pos2< low || pos1> high)
		return 0;
	
	int mid = (low + high) / 2;

	return 	Range(pos1, pos2, arr, low, mid, 2 * root + 1)
		+ Range(pos1, pos2, arr, mid + 1, high, 2 * root + 2);
}

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int n = ReadInt();
	int q = ReadInt();

	int l = 1;
	while (n > l)
		l = l * 2;
	l *=2;
	l--;
	vector<int> arr(l);

	while (q--)
	{
		string op;
		std::cin >> op;

		if (op == "add")
		{
			int pos;
			std::cin >> pos;
			pos--;
			int val;
			std::cin >> val;
			Update(pos, arr, l - 1, 0, n-1, val,0);
		}
		else
		{
			int pos1;
			std::cin >> pos1;
			pos1--;
			int pos2;
			std::cin >> pos2;
			pos2--;
			cout << Range(pos1, pos2, arr, 0, n -1, 0) << endl;

			/*std::cout << (Sum(pos2, arr, l) - Sum(pos1, arr, l)) << std::endl;*/
		}
	}

	//int xx = ReadInt();

    return 0;
}



