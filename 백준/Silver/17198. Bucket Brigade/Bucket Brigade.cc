#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

char graph[11][11];
int visited[11][11];
pii start;
pii dir[4] = {{-1, 0},
              {0,  1},
              {1,  0},
              {0,  -1}};


void INPUT()
{
    IAMFAST
    for (int i = 0; i < 10; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < 10; j++)
        {
            graph[i][j] = str[j];
            if (str[j] == 'B')
                start = {i, j};
        }
    }
}

int BFS(int sx, int sy)
{
    queue<pii> q;
    q.emplace(sx, sy);
    visited[sx][sy] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (graph[x][y] == 'L') return visited[x][y] - 2;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || 10 <= nx || 10 <= ny) continue;
            if (graph[nx][ny] == 'R') continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
}

void solution()
{
    cout << BFS(start.first, start.second);
}

int main()
{
    INPUT();
    solution();
}