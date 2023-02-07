#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int A[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int l = 0, r = 0;
	long long n, m;
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	long long sum = A[0];
	while (1) {
		if (sum < m) {
			r++;
			if (r >= n) {
				break;
			}
			sum += A[r];
		}
		else if (sum > m) {
			sum -= A[l];
			l++;
		}
		else {
			ans++;
			sum -= A[l];
			l++;
			r++;
			if (r >= n) {
				break;
			}
			sum += A[r];
		}
	}
	cout << ans;
}
