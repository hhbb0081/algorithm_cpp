#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

int cnt[4];
bool isDir[4];
vector <pair<int, int>> box;
//vector <pair<int, int>> subArea;
int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	
	int k;
	cin >> k;
	for (int i = 0; i < 6; i++) {
		int dir, len;
		cin >> dir >> len;
		box.push_back({ dir, len });

		if (isDir[dir - 1] == true) {
			isDir[dir - 1] = false;
		}
		else {

			isDir[dir - 1] = true;
		}
		cnt[dir - 1] += len;
	}

	int tmp = 0;
	int ans = 1;
	for (int i = 0; i < 6; i++) {
		if (isDir[box[i].first - 1] == true) {
			if (tmp == 0 && i == 5) { tmp = 6; }
			else { tmp = i; }
			ans *= box[i].second;
		}
	}

	int subArea = 1;
	if (tmp + 2 >= 6) {
		subArea *= box[tmp - 4].second;
		subArea *= box[tmp - 3].second;
	}
	else {
		subArea *= box[tmp + 2].second;
		if (tmp + 3 >= 6) {
			subArea *= box[tmp - 3].second;
		}
		else {
			subArea *= box[tmp + 3].second;
		}
	}

	cout << k * (ans - subArea) << endl;
}