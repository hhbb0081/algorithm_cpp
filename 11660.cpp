#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int sum[1030][1030];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				sum[i][j] = 0;
				continue;
			}

			int num;
			cin >> num;

			
			if (i > 1 && j > 1) {
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + num;
			}
			else if (i == 1 && j > 1) {
				sum[i][j] = sum[i][j - 1] + num;
			}
			else if (i > 1 && j == 1) {
				sum[i][j] = sum[i - 1][j] + num;
			}
			else {
				sum[i][j] = num;
			}
			
		}
	}


	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}
}