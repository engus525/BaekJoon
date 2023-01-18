#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int n, m;
char map[51][51];
int visited[51][51];

// 우 하 상 좌
int dir[4][2] = {{0,1},{1,0},
                 {-1,0},{0,-1}};

void INPUT()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%1s", &map[i][j]);
}

int BFS(int a, int b)
{
    int dist = 0; // 반환할 최대 거리

    queue<pair<int,int>> q;
    q.push({a,b});
    visited[a][b] = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(visited[nx][ny] == -1 && map[nx][ny] != 'W')
                {
                    q.push({nx,ny});
                    visited[nx][ny] = visited[x][y] + 1;
                    dist = max(dist, visited[nx][ny]);
                }
            }
        }// for end
    }

    return dist;
}

void SOLVE()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 'L')
            {
                memset(visited, -1, sizeof(visited));
                ans = max(ans, BFS(i,j));
            }
        }


    cout << ans;

}

int main()
{
    INPUT();
    SOLVE();
}
