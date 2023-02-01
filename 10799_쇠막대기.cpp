#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

stack <char> tree;
int main() {
	string str;
	cin >> str;

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		
		if (i == 0) {
			tree.push('(');
			continue;
		}
		if (str[i] == '(') {
			tree.push('(');
		}
		else {
			if (str[i - 1] == '(') {
				tree.pop();
				ans += tree.size();
				for (int j = 0; j < cnt; j++) {
					tree.pop();
				}
				cnt = 0;
			}
			else {
				cnt++;
			}
		}
	}
	ans += cnt;
	cout << ans;
}