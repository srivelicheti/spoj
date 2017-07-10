// Baby.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>

using namespace std;
const int maxState = 0b1111111111111111;

int mem[maxState][15];

int movesRequired(int cRow, int cCol, int fRow, int fCol)
{
	/*if (cRow == fRow && cCol == fCol)
		return 0;*/
	return abs(fRow - cRow) + abs(fCol - cCol);
}

int SolveInter(int state, int q, int& n, int& fullState , int cState[15] , int fState[15] )
{
	if (q < 0)
		return 0;
	if (state == fullState)
		return 0;

	if (mem[state][q] != -1)
		return mem[state][q];

	int minmnov = numeric_limits<int>::max();

	for (int i = 0; i < n; ++i)
	{
		int m = 1 << i;
		if((state & m) == 0)
		{
			int newState = state | m;
			int movesReq = movesRequired(q, cState[q], n -1 - i, fState[n - 1 - i]);
			int totalMoves = movesReq + SolveInter(newState, q -1, n, fullState, cState, fState);
			minmnov = min(minmnov, totalMoves);
		}
	}
	mem[state][q] = minmnov;

	return minmnov;
}

void Solve(int n)
{
	
	int state = pow(2, n) - 1;
	int temp = n;
	int cState[15];
	int fState[15];
	int i = 0;
	while(i < n)
		cin >> cState[i++];
	i = 0;
	while (i < n)
		cin >> fState[i++];
	memset(mem, -1, sizeof(mem[0][0]) * maxState * 15);
	
	cout << SolveInter(0, n - 1, n, state, cState, fState) << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int n;
	cin >> n;

	while(n !=0)
	{
		Solve(n);
		cin >> n;
	}

    return 0;
}

