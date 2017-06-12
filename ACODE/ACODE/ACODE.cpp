// ACODE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	

	while (true) {
		string in;
		getline(cin, in);
		
		if(in == "0")
			break;

		long cache[5001];

		cache[0] = 1;
		cache[1] = 1;
		//cache[2] = 2;

		auto l = in.length();

		for (int i = 1; i < l; ++i)
		{
			cache[i + 1] = 0;
			if (in[i] != '0')
				cache[i + 1] = cache[i];
			if(in[i-1] !='0')
			{
				char te[] = { in[i - 1], in[i] };
				int temp = atoi(te);
				if (temp <= 26)
				{
					cache[i + 1] += cache[i - 1];
				}
			}
			if(in[i] == '0' && in[i-1] == '0')
				cache[i + 1] = cache[i - 2];
		}

		cout << cache[l] << endl;



	}

    return 0;
}

