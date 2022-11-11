#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int r[4] = {1, -1, 0, 0};
int c[4] = {0, 0, 1, -1};
bool arr[251][251];
int land;
vector<int> ans;

int bfs(int n, int m)
{
  int cnt = 1;
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + r[i];
      int ny = y + c[i];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n)
      {
        if (arr[nx][ny] == false)
        {
          arr[nx][ny] = true;
          cnt++;
          q.push({nx, ny});
        }
      }
    }
  }
  return cnt;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m, n, k;
  cin >> m >> n >> k;
  while (k--)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = y1; i < y2; i++)
    {
      for (int j = x1; j < x2; j++)
      {
        arr[i][j] = true;
      }
    }
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] == false)
      {
        arr[i][j] = true;
        q.push({i, j});
        land++;
        int tmp = bfs(n, m);
        ans.push_back(tmp);
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << land << "\n";
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}