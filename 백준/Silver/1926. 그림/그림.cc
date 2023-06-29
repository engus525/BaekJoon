#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m;
int map[501][501];
bool visited[501][501];
pair<int, int> dir[4] = {{-1, 0},
                         {1,  0},
                         {0,  -1},
                         {0,  1}};

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
}

int DFS(int x, int y)
{
    int size = 1;

    visited[x][y] = true;

    for (auto &d: dir)
    {
        int nx = x + d.first;
        int ny = y + d.second;
        if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
        if (visited[nx][ny]) continue;
        if (map[nx][ny] == 0) continue;

        size += DFS(nx, ny);
    }

    return size;
}

void SOLVE()
{
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j] && map[i][j])
                cnt++,
                ans = max(ans, DFS(i, j));

    cout << cnt << '\n' << ans;
}

int main()
{
    INPUT();
    SOLVE();
}