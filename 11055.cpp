#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans = dp[i];
		}
		for (int j = 0; j < i; j++) {
			//증가 수열 조건 만족
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[j] + arr[i], dp[i]);
			}

			//증가 수열 조건 불만족
			else continue;

		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}