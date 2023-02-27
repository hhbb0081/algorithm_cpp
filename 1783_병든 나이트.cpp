#include <iostream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	else if (n == 2) {
		if (m <= 6) {
			cout << (m + 1) / 2 << endl;
			return 0;
		}
		else {
			cout << 4 << endl;
		}
	}
	else {
		if (m < 6) {
			cout << min(4, m) << endl;
		}
		else {
			cout << m - 2 << endl;
		}
	}
}