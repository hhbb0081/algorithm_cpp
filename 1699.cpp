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
		//�ִ��� �� ������ dp������ �ʱ�ȭ
		dp[i] = i;
		//i�� �����ٺ��� ���� ���� ���ʷ� Ž���ϸ� �ּ� �� ������ ������ �� ����
		for (int j = 1; j <= int(sqrt(i)); j++) {
			if (dp[i] > dp[i - j * j] + 1) {
				dp[i] = dp[i - j * j] + 1;
			}
		}
	}
	cout << dp[n];
}