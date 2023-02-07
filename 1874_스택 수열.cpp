#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector <int> v;
vector <char> ans;
stack <int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}


	int x = 1;
	st.push(0);
	for (int i = 0; i < n; i++) {
		int tmp = v[i];
		while (1) {
			if (st.top() < tmp) {
				st.push(x++);
				ans.push_back('+');
			}
			int now = st.top();
			if (now < tmp) {
				continue;
			}
			else if (now == tmp){
				st.pop();
				ans.push_back('-');
				break;
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}