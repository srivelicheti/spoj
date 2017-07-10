// ALTSEQ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int n;
	cin >> n;

	vector<int> v(n);

	int i = 0;
	while(i < n)
	{
		cin >> v[i];
		i++;
	}
	vector<int> dp(n);
	int res = 1;
	for (i = 0; i < n; ++i)
	{
		dp[i] = 1;
		auto cSignBit = v[i]<0;
		for (int j = 0; j < i; ++j)
		{
			if ((v[j] < 0) != cSignBit && dp[j] >= dp[i] && abs(v[j]) < abs(v[i]))
				dp[i] = dp[j] + 1;
		}
		res = max(res, dp[i]);
	}
	cout << res << endl;
    return 0;
}

