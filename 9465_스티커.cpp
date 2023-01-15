#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[2][100001];
int arr[2][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = dp[1][0] + arr[0][1];
		dp[1][1] = dp[0][0] + arr[1][1];

		for (int k = 2; k < n; k++) {
			dp[0][k] = max(dp[1][k - 1], dp[1][k - 2]) + arr[0][k];
			dp[1][k] = max(dp[0][k - 1], dp[0][k - 2]) + arr[1][k];
		}
		
		
		int ans = 0;
		ans = max(dp[0][n - 1], dp[1][n - 1]);
		cout << ans << "\n";

	}
}
