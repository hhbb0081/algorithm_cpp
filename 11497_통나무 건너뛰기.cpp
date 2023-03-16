#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

int arr[10001];
int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		//Á¤·Ä
		sort(arr, arr + n);

		for (int i = 1; i < n / 2; i++) {
			ans = max(ans, arr[i * 2] - arr[(i - 1) * 2]);
			ans = max(ans, arr[i * 2 + 1] - arr[(i - 1) * 2 + 1]);
		}
		if (n % 2 == 1) {
			ans = max(ans, arr[(n / 2) * 2] - arr[(n / 2 - 1) * 2]);
		}
		cout << ans << "\n";
	}
}