#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

set <string> subSet;
int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str.length(); j++) {
			string tmp = str.substr(i, j);
			subSet.insert(tmp);
		}
	}

	cout << subSet.size() << endl;

}