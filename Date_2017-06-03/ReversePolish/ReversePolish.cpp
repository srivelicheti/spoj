// ReversePolish.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace std;

bool isOperand(char c)
{
	return c == '*' || c == '+' || c == '-' || c == '/' || c=='^';
}

int main()
{

#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int i = 10;
	cout << hex << ~i << endl;
	int n;
	cin >> n;
	stack<string> res;
	stack<char> op;
	while(n--)
	{
		string s;
		cin >> s;
		for (char c : s)
		{
			if(c == '(')
				continue;

			if (c == ')')
			{
				string cop(1, op.top()); op.pop();
				auto op1 = res.top(); res.pop();
				auto op2 = res.top(); res.pop();
				auto cres = op2 + op1 + cop;
				res.push(cres);
			}
			else if (isOperand(c))
				op.push(c);
			else
				res.push(string(1, c));
		}
		cout << res.top() << endl;
		res.pop();
		
	}

    return 0;
}

