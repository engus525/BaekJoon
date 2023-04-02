#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // cpp
#include <algorithm>
using namespace std;

int n;
int map[501][501];
int visited[501][501];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; // 상 우 하 좌

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            visited[i][j] = -1;
        }
}

int DFS(int x, int y)
{
    if (visited[x][y] != -1) return visited[x][y];

    visited[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= n)
        {// Check range
            if (map[x][y] < map[nx][ny])
            {// if next position has more bamboos
                visited[x][y] = max(visited[x][y], DFS(nx, ny));
            }
        }
    }
    return ++visited[x][y];
}

void SOLVE()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, DFS(i, j));
        }

    cout << ans;
}


int main()
{
    INPUT();

    SOLVE();
}