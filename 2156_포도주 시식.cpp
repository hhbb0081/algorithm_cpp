#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[100001];
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == 1) {
			dp[i] = arr[i];
		}
		else if (i == 1) {
			dp[i] = dp[0] + arr[i];
		}
		else {
			dp[i] = max({ dp[i - 2] + arr[i], dp[i - 3] + arr[i] + arr[i - 1], dp[i - 1]});
		}
	}
	cout << dp[n];
}