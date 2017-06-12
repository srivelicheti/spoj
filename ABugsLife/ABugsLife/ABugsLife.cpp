// ABugsLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int t;
	cin >> t;
	int i = 1;
	while (t--) {
		int n;
		cin >> n;
		int it;
		cin >> it;
		short* v = new short[n + 1];
		memset(&v[0], 0, (n +1) * sizeof v[0]);

		while (it--) {
			int b1;
			cin >> b1;
			int b2;
			cin >> b2;
			int vb1 = v[b1];
			int vb2 = v[b2];
			if (vb1 == 0 && vb2 == 0) {
				v[b1] = 1; v[b2] = -1;
			}
			else if (vb1 != 0 && vb2 != 0) {
				if (vb1 == vb2) {

					break;
				}
			}
			else if (vb1 == 0 && vb2 != 0) {
					v[b1] = -1 * vb2;
			}
			else if (vb1 != 0 && vb2 == 0) {
					v[b2] = -1 *vb1;
			}

		}
		cout << "Scenario #" << i << ":" << "\n";
		if (it == -1)
			cout << "No suspicious bugs found!" << "\n";
		else
			cout << "Suspicious bugs found!" << "\n";

		i++;
		delete v;

	}

	// your code goes here
	return 0;
}