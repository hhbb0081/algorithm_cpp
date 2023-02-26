#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int arr[1001];
int dp[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans + 1;
}