// ADFRUITS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <array>
#include <cmath>
#include <fstream>

using  namespace std;

int getmin(int l1, int l2, int l3)
{
	return min(min(l1, l2), l3);
}

int main()
{
	ios::sync_with_stdio(false);
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	while (true) {
		
		if(cin.eof())
			break;

		string s1;
		cin >> s1;
		
		string s2;
		cin >> s2;

		string mem[101][101];

		mem[0][0] = "";
		for (int i = 1; i <= s1.length(); ++i)
			mem[i][0] = s1.substr(0, i);

		for (int i = 1; i <= s2.length(); ++i)
			mem[0][i] = s2.substr(0, i);


		for (int i = 1; i <= s1.length(); ++i)
		{
			for (int j = 1; j <= s2.length(); ++j)
			{
				if(s1[i-1] == s2[j-1])
				{
					mem[i][j] = mem[i - 1][j - 1] + s1[i - 1];
					continue;
				}

				auto l1 = (mem[i - 1][j]).length() + 1;
				auto l2 = (mem[i][j - 1]).length() + 1;
				auto l3 = (mem[i - 1][j - 1]).length() + 2;
				auto m = getmin(l1, l2, l3);
				if (l1 == m)
				{
					mem[i][j] = mem[i - 1][j] + s1[i - 1];
				}
				else if(l2 == m)
				{
					mem[i][j] = mem[i][j-1] + s2[j - 1];
				} 
				else
				{
					mem[i][j] = mem[i][j - 1] + s1[i-1] + s2[j - 1];
				}

			}
		}
		cout << mem[s1.length()][s2.length()] << endl;

	}

    return 0;
}

