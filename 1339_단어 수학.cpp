#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;

int word[11][9];
int alpha[26];
//문자열의 길이, 문자열의 번호
priority_queue <pair<int, int>> len;
//알파벳, 알파벳에 할당된 숫자

int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int now = 1;
		for (int j = str.length() - 1; j >= 0; j--) {
			alpha[str[j] - 'A'] += now;
			now *= 10;
		}

	}

	sort(alpha, alpha + 26);

	int num = 9;
	int ans = 0;
	for (int i = 25; i >= 0; i--) {
		ans += (alpha[i] * num);
		num--;
	}
	cout << ans;
}
