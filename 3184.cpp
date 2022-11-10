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
bool visited[251][251];
char garden[251][251];
int cnto, cntv;
int tmpo, tmpv;

void bfs(int tmpo, int tmpv)
{
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + r[i];
      int ny = y + c[i];
      if (visited[nx][ny] == false && garden[nx][ny] == '.')
      {
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
      else if (visited[nx][ny] == false && garden[nx][ny] == 'o')
      {
        tmpo++;
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
      else if (visited[nx][ny] == false && garden[nx][ny] == 'v')
      {
        tmpv++;
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
      else
      {
        continue;
      }
    }
  }
  if (tmpo > tmpv)
  {
    cnto += tmpo;
  }
  else
  {
    cntv += tmpv;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> garden[i][j];
    }
  }
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (visited[i][j] == false && garden[i][j] != '#')
      {
        q.push({i, j});
        if (garden[i][j] == 'o')
        {
          tmpo++;
        }
        else if (garden[i][j] == 'v')
        {
          tmpv++;
        }
        visited[i][j] = true;
        bfs(tmpo, tmpv);
        tmpo = 0;
        tmpv = 0;
      }
    }
  }
  cout << cnto << " " << cntv;
}