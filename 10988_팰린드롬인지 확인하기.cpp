#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - 1 - i]) {
			cout << "0" << endl;
			return 0;
		}
	}
	cout << "1" << endl;
}
