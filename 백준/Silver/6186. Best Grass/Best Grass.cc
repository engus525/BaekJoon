#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


int n, m;
char graph[101][101];
bool visited[101][101];
pii dir[4] = {{-1, 0},
              {0,  1},
              {1,  0},
              {0,  -1}};


void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < m; j++)
            graph[i][j] = str[j];
    }
}

void BFS(int sx, int sy)
{
    queue<pii> q;
    q.emplace(sx, sy);
    visited[sx][sy] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
            if (graph[nx][ny] == '.') continue;
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
            if (!visited[i][j] && graph[i][j] == '#')
                BFS(i, j), ans++;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}