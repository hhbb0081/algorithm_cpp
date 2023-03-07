#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;

string a[51];
string b[51];

//a와 b의 차이 여부를 나타내는 행렬
int c[51][51];

int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	//if (n < 3 || m < 3) { cout << "-1" << endl; return 0; }

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == b[i][j]) {
				c[i][j] = 0;
			}
			else {
				c[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (c[i][j] == 0) { continue; }
			else{
				ans++;
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (c[i + x][j + y] == 1) {
							c[i + x][j + y] = 0;
						}
						else {
							c[i + x][j + y] = 1;
						}

					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == 1) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}

	cout << ans << endl;
	return 0;
}