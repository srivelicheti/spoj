// ACTIV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

bool sortbysec(const pair<int, int> &a,
	const pair<int, int> &b)
{
	return (a.second < b.second);
}

int binarySearchLessThan(int i, int j, int e, vector<pair<int, int>>& v)
{
	if (j < i)
		return -1;

	if (i == j)
		return v[i].second <= e ? i : -1;

	int mid = (i + j) / 2;
	if (v[mid].second == e)
	{
		//Check if there is anyting in the second half which is equal to this
		auto resFromsecond = binarySearchLessThan(mid + 1, j, e, v);
		return resFromsecond != -1 ? resFromsecond : mid;
	}


	if (e > v[mid].second)
	{
		int curLower = mid;
		auto res = binarySearchLessThan(mid + 1, j, e, v);
		if (res == -1) return curLower;
		else return res;
	}
	else
		return binarySearchLessThan(i, mid, e, v);

}

int binarySearchLessThan(int i, int j, int e, vector<int>& v)
{
	if (j < i)
		return -1;
	if (i == j)
		return v[i] <= e ? i : -1;

	int mid = (i + j) / 2;
	if (v[mid] == e)
		return mid;


	if (e > v[mid])
	{
		int curLower = mid;
		auto res = binarySearchLessThan(mid + 1, j, e, v);
		if (res == -1) return curLower;
		else return res;
	}
	else
		return binarySearchLessThan(i, mid, e, v);

}

int main()
{
	ios::sync_with_stdio(false);



#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	while (true)
	{
		int t;
		cin >> t;
		if (t == -1)
			break;

		int temp = t;

		vector<pair<int, int>> v;
		v.push_back({ 0,0 });
		while (temp--)
		{
			int s;
			cin >> s;
			int e;
			cin >> e;
			v.push_back({ s,e });
		}

		sort(v.begin(), v.end(), sortbysec);
		vector<int> res(t + 1);
		res[0] = 1;
		res[1] = 1;
		int mod = pow(10, 8);
		for (int i = 2; i <= t; ++i)
		{
			res[i] = 1; //for just this class alone add 1 and then if we dont take this class

			int lower = binarySearchLessThan(1, i - 1, v[i].first, v);
			if (lower != -1)
			{
				res[i] = (res[i] %mod + res[lower] %mod) % mod;
			}
		//	if (lower < i - 1)
				res[i] = (res[i] % mod + res[i - 1] % mod) % mod;
		}
		cout << setfill('0') << std::setw(8) << res[t] << endl;
	}

	return 0;
}

