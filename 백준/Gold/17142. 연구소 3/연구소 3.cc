#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int,int> pii;

int n, m;
int cleanArea = 0;
int map[51][51];
int visitedBFS[51][51], visited[51][51];
vector<pii> virus;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int ans = 1e9;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 0) cleanArea++;
        }

}

int BFS()
{
    int time = 0; //바이러스가 모두 전파되는 시간
    int ca = cleanArea;

    queue<pii> q;
    for(int i = 0; i < virus.size(); i++)
    {
        q.push(virus[i]);
        visitedBFS[virus[i].first][virus[i].second] = 0;
    }

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if(visitedBFS[nx][ny] == -1 && map[nx][ny] != 1)
                {// 방문하지 않은 지점이면서 벽이 아니라면 바이러스 전파
                    q.push({nx,ny});
                    visitedBFS[nx][ny] = visitedBFS[x][y] + 1;
                    if(map[nx][ny] == 0) ca--;
                    time = max(time,visitedBFS[nx][ny]);
                    if(ca == 0) return time;
                }
            }
        }
    }
    return -1;
}

void permutation(int cnt, int limit, pii start)
{
    if(cnt == limit)
    {
        memset(visitedBFS, -1, sizeof(visitedBFS));
        int bfs = BFS();
        if(bfs >= 0) ans = min(ans,bfs);
        return;
    }

    bool init = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!init)
            {
                i = start.first;
                j = start.second;
                init = true;
            }

            if(!visited[i][j] && map[i][j] == 2)
            {
                virus.push_back({i,j});
                visited[i][j] = 1;
                permutation(cnt + 1, limit, {i,j});
                virus.pop_back();
                visited[i][j] = 0;
            }
        }
    }
}

void SOLVE()
{
    if(cleanArea == 0)
    {
        cout << 0;
        return;
    }
    permutation(0,m, {0,0});

    if(ans == 1e9) cout << -1;
    else cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
