#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 100001
using namespace std;

int n;
vector<int> tree[MAX];
queue<int> q;
bool visited[MAX];
int parent[MAX];

void bfs() {
	q.push(1);

	while(!q.empty()) {
		int start = q.front();
		q.pop();
		visited[start] = true;
		while (!tree[start].empty()) {
			int v = tree[start].back();
			tree[start].pop_back();

			if (!visited[v] && parent[v] == 0) {
				parent[v] = start;
				q.push(v);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		tree[b].push_back(a);
		tree[a].push_back(b);
	}
	bfs();
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
}