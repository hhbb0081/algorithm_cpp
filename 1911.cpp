#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector <pair<int, int>> pool;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		pool.push_back({ start, end });
	}

	sort(pool.begin(), pool.end());
	int cur = pool[0].first;
	for (int i = 0; i < n; i++) {
		if (cur < pool[i].first) { cur = pool[i--].first; }

		else if (pool[i].first <= cur && cur < pool[i].second) {
			int sub = pool[i].second - cur;
			ans += sub / l;
			cur += (sub / l) * l;

			if (sub % l != 0) {
				ans++;
				cur += l;
			}
		}
	}
	cout << ans;
}