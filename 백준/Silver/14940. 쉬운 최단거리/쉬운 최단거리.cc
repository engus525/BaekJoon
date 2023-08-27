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
typedef pair<long long, long long> pll;


int n, m;
int graph[1001][1001];
int visited[1001][1001];
pii dir[4] = {{-1, 0},
              {0,  1},
              {1,  0},
              {0,  -1}};
pii start;


void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 2) start = {i, j};
        }
}

void BFS()
{
    queue<pii> q;
    q.emplace(start);
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
            if (graph[nx][ny] == 0) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
}

void solution()
{
    BFS();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0) cout << 0 << " ";
            else if (visited[i][j] == 0) cout << -1 << " ";
            else cout << visited[i][j] - 1 << " ";
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}