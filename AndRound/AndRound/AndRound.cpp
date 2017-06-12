// AndRound.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <fstream>
#include <climits>
using namespace std;

void CreateSegmentTree(int i ,int j, std::vector<long long>& input, std::vector<long long>& sg, int root)
{
	if (i == j) {
		sg[root] = input[i];
		return;
	}

	int mid = (i + j) / 2;
	CreateSegmentTree(i, mid, input, sg, 2 * root + 1);
	CreateSegmentTree(mid+1, j, input, sg, 2 * root + 2);
	sg[root] = sg[2 * root + 1] & sg[2 * root + 2];
}

long long Sum(int qi, int qj, int i, int j, vector<long long>& sg, int root)
{
	if (qi > j || qj < i)
		return 1152921504606846975;
	if (qi <= i && qj >= j)
		return sg[root];

	int mid = (i + j) / 2;
	return Sum(qi, qj, i, mid, sg, 2 * root + 1) & Sum(qi, qj, mid + 1, j, sg, 2 * root + 2);
	
}	

int ReadInt()
{
	int i;
	cin >> i;
	return  i;
}

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int t = ReadInt();
	while(t--)
	{
		
		int l = ReadInt();
		int k = ReadInt();
		vector<long long> v(l);
		int temp = l;
		int i = 0;
		while(temp--)
		{
			cin >> v[i];
			i++;
		}
		auto sgSize = static_cast<int>(pow(2, (ceil(log2(l)) + 1)) -1);
		vector<long long> sg (sgSize );
	/*	vector<int> o{ l };*/
		CreateSegmentTree(0, l - 1, v, sg, 0);
		for (int j = 0; j < l; ++j)
		{
			int low = j - k;
			int high = j + k;
			int o;
			if (low >= 0 && high < l)
				o = Sum(low, high, 0, l - 1, sg, 0);
			else if (low < 0 & high < l)
			{
				int low1 = l + low;
				auto o1 = Sum(0, high, 0, l - 1, sg, 0);
				auto o2 = Sum(low1, l - 1, 0, l - 1, sg, 0);
					o = o1 & o2;
			}
			else if (low >= 0 && high >= l)
			{
				int high1 = high - l;
				o = Sum(low, l - 1, 0, l - 1, sg, 0) & Sum(0, high1, 0, l - 1, sg, 0);
			}
			else
				o = Sum(0, l - 1, 0, l - 1, sg, 0);

			if (j == 0)
				cout << o;
			else
				cout << " " << o;
		}
		cout << endl;


	}

    return 0;
}

