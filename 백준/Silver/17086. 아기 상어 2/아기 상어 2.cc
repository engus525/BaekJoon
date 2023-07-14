#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m;
int map[51][51];
int visited[51][51];
typedef pair<int, int> pii;
//pii dir[8] = {{-2, 1},
//              {-1, 2},
//              {1,  2},
//              {2,  1},
//              {2,  -1},
//              {1,  -2},
//              {-1, -2},
//              {-2, -1}};
pii dir[8] = {{0,  1},
              {0,  -1},
              {1,  0},
              {-1, 0},
              {1,  1},
              {-1, -1},
              {-1, 1},
              {1,  -1}};

void INPUT()
{
    IAMFAST
    cin >> n >> m;
   for(int i = 0; i < n; i++)
       for(int j = 0; j < m; j++)
           cin >> map[i][j];
}

int BFS(int sx,int sy)
{

    queue<pii> q;
    q.emplace(sx, sy);
    visited[sx][sy] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (map[x][y] == 1) return visited[x][y];

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || n <= nx || ny < 0 || m <= ny)
                continue;
            if (visited[nx][ny] != -1) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
    return 0;
}

void solution()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(map[i][j] == 0)
            {
                memset(visited, -1, sizeof visited);
                ans = max(ans,BFS(i,j));
            }

    cout << ans;
}

int main()
{
    INPUT();
    solution();
}