#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;

int n, m;
char graph[1001][1001];
int visited[1001][1001];
int fireTime[1001][1001];
vector<pii> fire;
pii start;
pii dir[8] = {{-1, 0},
              {0,  1},
              {1,  0},
              {0,  -1}};


void INPUT()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%1s", &graph[i][j]);
            if (graph[i][j] == 'F') fire.emplace_back(i, j);
            else if (graph[i][j] == 'J') start = {i, j};
        }
}

void spreadFire()
{
    queue<pii> q;
    for (auto &i: fire)
        q.emplace(i), fireTime[i.first][i.second] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
            if (graph[nx][ny] == '#') continue;
            if (fireTime[nx][ny] != -1) continue;

            fireTime[nx][ny] = fireTime[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
}

int BFS(pii s)
{
    queue<pii> q;
    q.emplace(s.first, s.second);
    visited[s.first][s.second] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || n <= nx || m <= ny)
                return visited[x][y] + 1;

            if (graph[nx][ny] == '#') continue;
            if (visited[nx][ny] != -1) continue;
            if (fireTime[nx][ny] != -1 && visited[x][y] + 1 >= fireTime[nx][ny]) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.emplace(nx, ny);
        }

    }
    return -1;
}

void solution()
{
    memset(visited, -1, sizeof visited);
    memset(fireTime, -1, sizeof fireTime);
    spreadFire();
    int ans = BFS(start);
    (ans >= 0) ? cout << ans : cout << "IMPOSSIBLE";
}

int main()
{
    INPUT();
    solution();
}