#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int r,c,k;
char map[6][6];
int visited[6][6];
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int ans = 0;

void INPUT()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%1s", &map[i][j]);
}

void DFS(int x, int y)
{
    if(x == 0 && y == c - 1)
    {
        if(visited[x][y] == k) ans++;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(0 <= nx && nx < r && 0 <= ny && ny < c)
        {
            if(visited[nx][ny] == 0 && map[nx][ny] != 'T')
            {
                visited[nx][ny] = visited[x][y] + 1;
                DFS(nx,ny);
                visited[nx][ny] = 0;
            }
        }
    }
}

void SOLVE()
{
    memset(visited,0,sizeof(visited));
    visited[r-1][0] = 1;

    DFS(r - 1, 0);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
