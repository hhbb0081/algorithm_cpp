#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

vector <string> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	char now = str[0];
	int cnt0 = 0, cnt1 = 0;

	//�� ó�� ���� ī��Ʈ
	if (now == '0') {
		cnt0++;
	}
	else {
		cnt1++;
	}
	for (int i = 1; i < str.length(); i++) {
		//�޶����� ���� ī��Ʈ
		if (str[i] != now) {
			if(str[i] == '0') {
				cnt0++;
			}
			else {
				cnt1++;
			}
			now = str[i];
		}
	}
	cout << min(cnt0, cnt1) << endl;
}