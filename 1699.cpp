#include <iostream>
#include <cmath>
#include <algorithm>
#include <typeinfo>
using namespace std;

int dp[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		//최대의 항 개수를 dp값으로 초기화
		dp[i] = i;
		//i의 제곱근보다 작은 수를 차례로 탐색하며 최소 항 개수를 가지면 값 갱신
		for (int j = 1; j <= int(sqrt(i)); j++) {
			if (dp[i] > dp[i - j * j] + 1) {
				dp[i] = dp[i - j * j] + 1;
			}
		}
	}
	cout << dp[n];
}