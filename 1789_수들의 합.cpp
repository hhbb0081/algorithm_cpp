#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	long long s;
	cin >> s;

	long long now = s;
	long long cnt = 1;
	int ans = 0;
	while (1) {
		if (now - cnt <= cnt) {
			cout << now << " ";
			ans++;
			break;
		}
		cout << cnt << " ";
		now -= cnt;
		cnt++;
		ans++;
	}
	cout << ans << endl;
}