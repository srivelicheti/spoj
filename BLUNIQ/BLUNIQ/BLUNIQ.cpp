// BLUNIQ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int t;
	cin >> t;
	map<int,int> set;
	while(t--)
	{
		int op;
		cin >> op;
		int code;
		cin >> code;
		if(op == 1)
		{
			auto f = set.find(code);
			if (f == set.end() || f->second == -1 ) {
				set[code] = 1;
			}
			else
			{
				auto next = set.upper_bound(code);
				
				while(next != set.end() && (next->first - code) <= 1 && next->second != -1)
				{
					code = next->first;
					std::advance(next, 1);
				}
				code = code + 1;
				set[code] = 1;
			}

			cout << code << endl;
		}
		else
		{
			set[code] = -1;
		}
	}

    return 0;
}

