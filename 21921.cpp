#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int visitor[250001];
vector <int> sum;

bool compare(int i, int j) {
	return j < i;
}

int main(void) {
	cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;

	visitor[0] = 0;
	cin >> visitor[1];
	if (x == 1) {
		sum.push_back(visitor[1]);
	}
	
	for (int i = 2; i <= n; i++) {
		cin >> visitor[i];
		visitor[i] = visitor[i - 1] + visitor[i];
		if (i >= x) {
			sum.push_back(visitor[i] - visitor[i - x]);
		}
	}
	
	
	sort(sum.begin(), sum.end(), compare);
	int cnt = 0;
	for (int i = 0; i < sum.size(); i++) {
		if (sum[0] == sum[i]) {
			cnt++;
		}
		else
			break;
	}
	if (sum[0] == 0) {
		cout << "SAD";
	}
	else {
		cout << sum[0] << "\n" << cnt;
	}
	
}