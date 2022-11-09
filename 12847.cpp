#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

long long money[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	cin >> money[0];
	for (int i = 1; i < n; i++) {
		cin >> money[i];
		money[i] += money[i - 1];
	}

	long long ans = money[m - 1];
	for (int i = m; i < n; i++) {
		ans = max(ans, money[i] - money[i - m]);
	}
	cout << ans;
}