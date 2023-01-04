#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[1001][10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	int sum = 0;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= 10007;
		}
	}
	
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
		sum %= 10007;
	}
	cout << sum;
}