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
	cout << ch << "\"����Լ��� ������?\"\n";
	

	if (i == n) {
		cout << ch << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		cout << ch << "��� �亯�Ͽ���.\n";
		return;
	}
	else { 
		cout << ch << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		cout << ch << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		cout << ch << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		rec(i + 1, n); 
		cout << ch << "��� �亯�Ͽ���.\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	rec(0, n);
	
}