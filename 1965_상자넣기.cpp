#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

int box[1001];
int dp[1001];
int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> box[i];
		dp[i] = 1;
	}

	int ans = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[j] < box[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}