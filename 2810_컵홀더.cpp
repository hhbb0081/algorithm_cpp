#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;

	int cnts = 0, cntl = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'S') {
			cnts++;
		}
		else {
			cntl++;
		}
	}
	if (cntl == 0) {
		cout << cnts << endl;
	}
	else {
		cout << cnts + (cntl / 2) + 1 << endl;
	}
}