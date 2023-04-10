#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
char map[301][301];
int visited[301][301];
typedef pair<int,int> pii;
pii dir[4] = {{0,1},
              {0,-1},
              {1,0},
              {-1,0}};
pii start,target;

void INPUT()
{
    //IAMFAST
    cin >> n >> m >> start.first >> start.second >> target.first >> target.second;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%1s", &map[i][j]);
}

int BFS()
{
    int ans = 2e9;
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = 1;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x==target.first && y==target.second)
        {
            ans = min(ans,visited[x][y]);
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx<1 || n<nx || ny<1 || m<ny) continue;
            //if(visited[nx][ny]) continue;

            if(map[nx][ny] == '0' &&
            (visited[nx][ny] == 0 || visited[x][y] < visited[nx][ny]))
                visited[nx][ny] = visited[x][y],
                q.push({nx,ny});
            else if(map[nx][ny] != '0' &&
            (visited[nx][ny] == 0 || visited[x][y]+1 < visited[nx][ny]))
                visited[nx][ny] = visited[x][y] + 1,
                q.push({nx,ny});

        }
    }
    return ans-1;
}

void SOLVE()
{
    cout << BFS();
}

int main()
{
    INPUT();
    SOLVE();
}