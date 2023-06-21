#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m,k;
int map[101][101];
bool visited[101][101];
pair<int,int> dir[4] = {{0,1},
                        {0,-1},
                        {1,0},
                        {-1,0}};

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int r,c; cin >> r >> c;
        map[r][c] = 1;
    }

}

int BFS(pair<int,int> s)
{
    int cnt = 1;
    queue<pair<int,int>> q;
    q.push(s);
    visited[s.first][s.second] = true;

    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if(nx < 1 || n < nx || ny < 1 || m < ny) continue;
            if(map[nx][ny] == 0) continue;
            if(visited[nx][ny]) continue;

            cnt++;
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    return cnt;
}

void SOLVE()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(!visited[i][j])
                if(map[i][j])
                    ans = max(ans,BFS({i,j}));
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}