// ALICECUB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

short flip(short in)
{
	if (in == 1)
		return 0;
	else
		return 1;
}

void SolveOne(vector<short> g[], int num)
{
	short cur[17];
	int xx = 1;
	while (xx <= 16) {
		cin >> cur[xx];
		xx++;
	}
	int maxSteps = 3;
	for (int i = 1; i <= 16 ; ++i)
	{
		if( (i<=8 && cur[i] == 0) || i>8 && cur[i] == 1)
			continue;
		if(maxSteps< 0)
			break;
		if(i<=8)
		{
			queue<pair<short,short>> q; 
			q.push({i,0});
			short tofind = 0;
			while(!q.empty() && cur[i] == 1)
			{
				auto p = q.front();
				q.pop();
				auto cured = g[p.first];
				auto curStep = p.second;
				if(curStep > 3) break;
				for (auto z : cured)
				{
					if (cur[z] == tofind) {
						if (z > 8) {
							cur[z] = 1;
							cur[i] = 0; 
							maxSteps = maxSteps - curStep -1;
							break;
						}
						else
							q.push({ z,curStep + 1 });
					}
				}
			}
		}
		else
		{
			queue<pair<short,short>> q;
			q.push({i,0});
			
			short tofind = 1;
			while (!q.empty() && cur[i] == 0)
			{
				auto p = q.front();
				q.pop();
				auto cured = g[p.first];
				auto curStep = p.second;
				maxSteps--;
				if (maxSteps < 0) break;
				for (auto z : cured)
				{
					if (cur[z] == tofind) {
						if (z <= 8) {
							cur[z] = 0;
							cur[i] = 1; 
							maxSteps = maxSteps - curStep - 1;
							break;
						}
						else
							q.push({z,curStep +1});
					}
				}
			}
		}
	}

	bool isInDesiredState = true;
	for (int i = 1; i <= 16; ++i)
	{
		if(i<=8 && cur[i] != 0)
		{
			isInDesiredState = false;break;
		}
		else if(i>8 && cur[i] != 1)
		{
			isInDesiredState = false; break;
		}
	}
	cout << "Case #" << num << ": ";
	if (isInDesiredState && maxSteps >= 0)
		cout << 3 - maxSteps << endl;
	else
		cout << "more" << endl;

}


int main()
{
	ios::sync_with_stdio(false);

#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int t;
	cin >> t;
	vector<short> g[17];
	g[1] = { 9,3, 2,5 };
	g[2] = { 10,1,4,6 };
	g[3] = { 11,1,4,7 };
	g[4] = { 12,2,3,8 };
	g[5] = { 13,1,6,7 };
	g[6] = { 14,2,5,8 };
	g[7] = { 15,5,8,3 };
	g[8] = { 16,4,6,7 };
	g[9] = { 1,10,11,13 };
	g[10] = { 2,9,12,14 };
	g[11] = {3,9,12,15 };
	g[12] = { 4,10,11,16 };
	g[14] = { 5,9,154,15 };
	g[15] = { 7,11,13,16 };
	g[16] = { 8,12,14,15 };
	int num = 1;
	while(t--)
	{
		SolveOne(g, num);
		num++;
	}
    return 0;
}

