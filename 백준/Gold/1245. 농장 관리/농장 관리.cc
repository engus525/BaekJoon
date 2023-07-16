#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int graph[101][71];
bool visited[101][71];
pii dir[8] = {{-1, 0},
              {-1, 1},
              {0,  1},
              {1,  1},
              {1,  0},
              {1,  -1},
              {0,  -1},
              {-1, -1}};


void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
}

void BFS(int sx, int sy, bool &isPeak)
{
    queue<pii> q;
    q.emplace(sx, sy);
    visited[sx][sy] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
            if (graph[nx][ny] > graph[x][y]) isPeak = false;
            if (graph[nx][ny] != graph[x][y]) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
}

void solution()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j])
            {
                bool isPeak = true;
                BFS(i, j, isPeak);
                if(isPeak) ans++;
            }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}