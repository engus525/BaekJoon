#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
char graph[601][601];
bool visited[601][601];
pii start;
pii dir[4] = {{0,  -1},
              {0,  1},
              {-1, 0},
              {1,  0}};

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = str[j];
            if (str[j] == 'I') start = {i, j}, visited[i][j] = true;
        }
    }
}

int BFS()
{
    int ans = 0;

    queue<pii> q;
    q.emplace(start);

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (graph[nx][ny] == 'X') continue;

            if (graph[nx][ny] == 'P') ans++;
            visited[nx][ny] = true;
            q.emplace(nx,ny);
        }
    }

    return ans;
}

void solution()
{
    int ans = BFS();
    (ans == 0) ? cout << "TT" : cout << ans;
}

int main()
{
    INPUT();
    solution();
}