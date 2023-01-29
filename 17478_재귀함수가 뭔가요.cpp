#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

void rec(int i, int n) {
	string ch = "";
	for (int k = 0; k < i; k++) {
		ch += "____";
	}
	cout << ch << "\"재귀함수가 뭔가요?\"\n";
	

	if (i == n) {
		cout << ch << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		cout << ch << "라고 답변하였지.\n";
		return;
	}
	else { 
		cout << ch << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		cout << ch << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		cout << ch << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		rec(i + 1, n); 
		cout << ch << "라고 답변하였지.\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	rec(0, n);
	
}