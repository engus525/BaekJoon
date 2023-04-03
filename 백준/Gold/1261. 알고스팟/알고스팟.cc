#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int m,n;
int map[101][101];
int visited[101][101];
typedef pair<int,int> pii;
pii dir[4] = {{0,1},
              {0,-1},
              {1,0},
              {-1,0}};
int ans = 2e9;

void INPUT()
{
   //IAMFAST
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%1d",&map[i][j]);
}

void BFS()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            visited[i][j] = -1;

    queue<pair<pii,int>> q;
    q.push({{1,1},0});
    visited[1][1] = 0;

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        //답 갱신
        if(x==n && y==m) ans = min(ans,cnt);

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx<1 || n<nx || ny<1 || m<ny) continue;

            //벽이면서 방문하지 않은 지점
            if(map[nx][ny] &&
            (visited[nx][ny] == -1 || visited[nx][ny] > cnt+1))
                q.push({{nx,ny},cnt+1}),
                visited[nx][ny] = cnt + 1;

            //벽이 아니고 방문하지 않은 지점
            if(!map[nx][ny] &&
            (visited[nx][ny] == -1 || visited[nx][ny] > cnt))
                q.push({{nx,ny},cnt}),
                visited[nx][ny] = cnt;

        }
    }
    return;
}

void SOLVE()
{
    BFS();
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}