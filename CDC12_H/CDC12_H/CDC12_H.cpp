// CDC12_H.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;


long long sum( vector<long long>& v,  vector<long long>& lazy,
	 int qi, int qj, int root, int i, int j, int len)
{
	if ( i > qj  || j < qi)
		return 0;

	if (i == j && i < len)
	{
		v[root] += lazy[root];
		lazy[root] = 0;
		return v[root];
	}

	int mid = (i + j) / 2;
	int r1 = 2 * root + 1;
	int r2 = 2 * root + 2;

	if (i >= qi && j <= qj)
	{
		auto temp = (lazy[root]);
		v[root] += (j - i + 1)  * temp;;
		lazy[r1] += temp;
		lazy[r2] += temp;
		lazy[root] = 0;
		return v[root];
	}

	
	v[root] += (j - i + 1)  * lazy[root];
	lazy[r1] += lazy[root];
	lazy[r2] += lazy[root];
	lazy[root] = 0;

	return sum(v, lazy, qi, qj, r1, i, mid, len) + sum(v, lazy, qi, qj, r2, mid + 1, j, len);
}

void Add( vector<long long>& v,  vector<long long>& lazy, int q,int qi,int qj, int root ,int i , int j, int len)
{
	
	if(qj < i || qi >j)
	{
		auto temp = (lazy[root]);
		v[root] += (j - i + 1)  * temp;
		if (i != j) {
			lazy[2 * root + 1] += temp;
			lazy[2 * root + 2] += temp;
		}
		lazy[root] = 0;
		return;
	}
	if (i == j && i < len)
	{
		v[root] += lazy[root];
		lazy[root] = 0;
		v[root] += q;
		return;
	}

	int r1 = 2 * root + 1;
	int r2 = 2 * root + 2;

	if(i>=qi && j<=qj)
	{
		auto temp =  (q + lazy[root]);
		v[root] += (j - i + 1)  * temp;
		lazy[r1] +=  temp;
		lazy[r2] += temp;
		lazy[root] = 0;
		return;
	}
	int mid = (i + j) / 2;
	
	v[root] += (j - i + 1)  * lazy[root];
	lazy[r1] += lazy[root];
	lazy[r2] += lazy[root];
	lazy[root] = 0;
	
	Add(v, lazy, q, qi, qj, r1, i, mid, len);
	Add(v, lazy, q, qi, qj, r2, mid+1, j, len);

	v[root] = v[r1] + v[r2];
}



void SolveOne(int i)
{
	int n;
	int q;
	//scanf_s("%d %d", &n, &q);
	cin >> n >> q;
	float t1 = log2f(n);
	int t2 = ceil(t1);
	int l = pow(2, t2 + 1);
	 vector<long long> v(l -1);
	 vector<long long> lazy(l - 1);
	memset(&v[0], 0, sizeof(v[0]) * v.size());
	memset(&lazy[0], 0, sizeof(lazy[0]) * lazy.size());
	printf("Scenario #%d:\n", i);
	while (q--)
	{
		string op;
		cin >> op;
		//scanf_s("%s", &op);
		if (op == "answer")
		{
			int s; int e;
			//scanf_s("%d %d", &s, &e);
			cin >> s >> e;
			s--;
			e--;
			if(s > e)
			{
				s = s ^ e;  // x now becomes 15 (1111)
				e = s ^ e;  // y becomes 10 (1010)
				s = s ^ e;
			}
			printf("%lld\n", sum(v, lazy, s, e, 0, 0, n - 1, l - 1));
		}
		else
		{
			int s; int e;
			//scanf_s("%d %d", &s, &e);
			cin >> s >> e;
			s--;
			e--;
			if (s > e)
			{
				s = s ^ e;  // x now becomes 15 (1111)
				e = s ^ e;  // y becomes 10 (1010)
				s = s ^ e;
			}
			Add(v, lazy, 1, s, e, 0, 0, n - 1, l - 1);
			printf("OK\n");
		}

	}


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
	int n;
	//scanf_s("%d", &n);
	cin >> n;
	int i = 1;
	while(n--)
	{
		SolveOne(i++);
	}

    return 0;
}

