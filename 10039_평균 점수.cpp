#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int score;
		cin >> score;
		if (score <= 40) {
			sum += 40;
		}
		else {
			sum += score;
		}
	}
	cout << sum / 5 << endl;
}