// COT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
#include <stdio.h>
#include	<cstdio>

using namespace std;


// no getchar_unlocked on Windows so just call getchar
inline int getchar_unlocked() { return getchar(); }


void scanint(int &x)
{
	register int c = getchar_unlocked();
	x = 0;
	for (; (c<48 || c>57); c = getchar_unlocked())
		;
	for (; c>47 && c<58; c = getchar_unlocked())
	{
		x = (x << 1) + (x << 3) + c - 48;
	}
}

bool SolveInternal(const vector<vector<int>>& g, const vector<int>& w, priority_queue<int>& pq, int u, int v, vector<bool>& visited, int k)
{
	if (u == v)
		return true;
	for (auto c : g[u])
	{
		if(!visited[c])
		{
			visited[c] = true;
			auto res = SolveInternal(g, w, pq, c, v, visited, k);
			if (res) {
				if (pq.size() < k)
					pq.push(w[c]);
				else if (pq.top() > w[c]) {
					pq.pop();
					pq.push(w[c]);
				}
				return true;
			}
		}
	}

	return false;
}

void Solve(const vector<vector<int>>& g, const vector<int>& w, int n)
{
	priority_queue<int> pq;
	vector<bool> visited(n+1);

	int u, v, k;
	cin >> u >> v >> k;
	visited[u] = true;
	auto res = SolveInternal(g, w, pq,u,v,visited,k);
	if(res)
	{
		if (pq.size() < k)
			pq.push(u);
		else if (pq.top() > u) {
			pq.pop();
			pq.push(u);
		}
	}

	cout << pq.top() << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int n, m;
	scanint(n);
	scanint(m);
	//cin >> n >> m;

	vector<int> w(n+1);
	vector<vector<int>> g(n + 1);
	int temp = n,temp2 = n-1;
	int i = 1;
	while(temp--)
	{
		cin >> w[i];
		i++;
	}
	while(temp2--)
	{
		int s, e;
		cin >> s >> e;
		g[s].push_back(e);
		g[e].push_back(s);
	}
	while(m--)
	{
		Solve(g, w,n);
	}


    return 0;
}

