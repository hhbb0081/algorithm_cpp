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
	for (int i = 0; i < n; i++) {
		int sub;
		sub = pool[i].second - pool[i].first;
		ans += sub / l;

		if (i != n - 1 && sub % l != 0) {
			//안 덮히고 남은 웅덩이와 다음 웅덩이까지의 거리의 합이 널빤지의 길이보다 작을 때
			if ((pool[i + 1].first - pool[i].second) + (sub % l) <= l) {
				ans++;
				pool[i + 1].first += (l - (pool[i + 1].first - pool[i].second + sub % l));
			}
			else {
				ans++;
			}
		}
		else if (i != n - 1 && sub % l == 0) { continue; }
		else if (i == n - 1 && sub % l != 0) {
			ans++;
		}
	}
	cout << ans;
}