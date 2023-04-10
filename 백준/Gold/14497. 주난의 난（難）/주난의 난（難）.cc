#include <iostream>
#include <queue>
#include <algorithm>
#include <ctime>

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

void BFS()
{
    int ans = 2e9;
    deque<pii> dq;
    dq.push_front(start);
    visited[start.first][start.second] = 1;

    while(!dq.empty())
    {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        if(x==target.first && y==target.second)
        {
            cout << visited[x][y]-1;
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx<1 || n<nx || ny<1 || m<ny) continue;
            if(visited[nx][ny]) continue;

            if(map[nx][ny] == '0')
                visited[nx][ny] = visited[x][y],
                dq.push_front({nx,ny});
            else if(map[nx][ny] != '0')
                visited[nx][ny] = visited[x][y] + 1,
                dq.push_back({nx,ny});

        }
    }
}

void SOLVE()
{
    BFS();
}

int main()
{
    INPUT();
    SOLVE();
}