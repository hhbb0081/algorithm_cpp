#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;

int cnt[26];
char ans[51];

int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		cnt[str[i] - 'A']++;
	}

	bool isSorry = false;
	int now = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0) { continue; }
		//해당 알파벳이 문자열에 존재할 때
		
		//홀수 개인 문자가 처음 등장했을 때
		if (cnt[i] % 2 == 1 && isSorry == false) {
			isSorry = true;
			ans[(str.length() - 1) / 2] = char(i + 'A');
			cnt[i]--;
			if (cnt[i] == 0) { continue; }
		}
		//홀수 개인 문자가 또 등장했을 때
		else if (cnt[i] % 2 == 1 && isSorry == true) {
			cout << "I'm Sorry Hansoo" << endl;
			return 0;
		}
		for (int j = now; j < now + (cnt[i] / 2); j++) {
			ans[j] = char(i + 'A');
			ans[str.length() - 1 - j] = char(i + 'A');
		}
		now += (cnt[i] / 2);
	}
	for (int i = 0; i < str.length(); i++) {
		cout << ans[i];
	}
}