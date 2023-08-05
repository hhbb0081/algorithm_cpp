#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 10001
using namespace std;

int n;
vector <pair<int, int>> graph[MAX];
bool visited[MAX];
int ans;

void dfs(int i, int value) {
	visited[i] = true;

	if (value > ans) {
		ans = value;
	}

	for (int j = 0; j < graph[i].size(); j++) {
		int u = graph[i][j].first;
		int v = graph[i][j].second;

		if (!visited[u]) {
			dfs(u, value + v);
		}
	}
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
		memset(visited, false, sizeof(visited));
	}
	cout << ans << endl;
}