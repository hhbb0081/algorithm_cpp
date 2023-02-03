#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <typeinfo>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

map<string, int> number;
map <int, string> name;

vector <string> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		number.insert({ str, i + 1 });
		name.insert({ i + 1, str });
	}
	for (int i = 0; i < m; i++) {
		string poket;
		cin >> poket;
		
		if (65 <= poket[0] && 90 >= poket[0]) {
			ans.push_back(to_string(number[poket]));
		}
		else {
			ans.push_back(name[stoi(poket)]);
		}
	
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}