#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//��, ��, ��, ��
int x[4] = { 0, 1, 0, -1 };
int y[4] = { 1, 0, -1, 0 };

queue <pair <int, char>> direc;
queue <pair <int, int>> snake;

int n, k;
int ans = 0;

bool map[102][102];
bool apple[102][102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		apple[x][y] = true;
	}

	int L;
	cin >> L;
	for (int i = 0; i < L; i++) {
		int c;
		char d;
		cin >> c >> d;
		direc.push({ c, d });
	}
	int chnT = direc.front().first;
	int chnD = direc.front().second;

	int nowX = 1, nowY = 1, nowD = 0;
	map[1][1] = true;
	snake.push({ 1, 1 });
	while (1) {

		nowX += x[nowD];
		nowY += y[nowD];

		//cout << nowX << " " << nowY << "\n";

		//���� �������� �� ĭ ����
		if (nowX <= n && nowX > 0 && nowY <= n && nowY > 0 && map[nowX][nowY] == false) {
			snake.push({ nowX, nowY });
			map[nowX][nowY] = true;
			//�ش� �ڸ��� ����� ���� ���
			if (apple[nowX][nowY] == false) {
				map[snake.front().first][snake.front().second] = false;
				snake.pop();
			}
			else {
				apple[nowX][nowY] = false;
			}
		}
		//���̳� �ڱ� ���� �΋H���� ���
		else {
			cout << ans + 1 << endl;
			return 0;
		}

		//���� �ٲٴ� �ð��̸� �ٲٱ� & �ð� ����
		if (++ans == chnT) {
			//cout << chnT << " " << chnD << "\n";
			//��ȸ��
			if (chnD == 'D' && nowD != 3) {
				nowD++;
			}
			else if (chnD == 'D' && nowD == 3) {
				nowD = 0;
			}
			//��ȸ��
			else if (chnD == 'L' && nowD != 0) {
				nowD--;
			}
			else {
				nowD = 3;
			}
			direc.pop();
			if (!direc.empty()) {
				
				chnT = direc.front().first;
				chnD = direc.front().second;
			}
		}
		/*
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		*/
	}
	cout << ans + 1 << endl;
}
