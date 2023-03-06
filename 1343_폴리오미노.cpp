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

	string str;
	cin >> str;
	
	//cnt는 연속된 X의 개수
	int cnt = 0;
	string ans = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'X') {
			cnt++;
		}
		else if(str[i] != 'X' && cnt != 0) {
			if (cnt < 2) { cout << "-1" << endl; return 0; }
			else if (cnt < 4) {
				if (cnt % 2 == 0) { ans += "BB"; }
				else { cout << "-1" << endl; return 0; }
			}
			else if (cnt >= 4) {
				if (cnt % 4 == 1 || cnt % 4 == 3) { cout << "-1" << endl; return 0; }
				else if (cnt % 4 == 0) {
					for (int j = 0; j < cnt / 4; j++) {
						ans += "AAAA";
					}
				}
				else {
					for (int j = 0; j < cnt / 4; j++) {
						ans += "AAAA";
					}
					ans += "BB";
				}
			}
			cnt = 0;
			ans += ".";
		}
		else if (str[i] != 'X' && cnt == 0) {
			ans += ".";
		}
	}
	if(cnt >= 1) {
		if (cnt < 2) { cout << "-1" << endl; return 0; }
		else if (cnt < 4) {
			if (cnt % 2 == 0) { ans += "BB"; }
			else { cout << "-1" << endl; return 0; }
		}
		else if (cnt >= 4) {
			if (cnt % 4 == 1 || cnt % 4 == 3) { cout << "-1" << endl; return 0; }
			else if (cnt % 4 == 0) {
				for (int j = 0; j < cnt / 4; j++) {
					ans += "AAAA";
				}
			}
			else {
				for (int j = 0; j < cnt / 4; j++) {
					ans += "AAAA";
				}
				ans += "BB";
			}
		}
	}
	cout << ans << endl;
}