#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int map[101][101];
bool visited[101][101];
typedef pair<int,int> pii;
pii dir[4] = {{0,1},
              {0,-1},
              {1,0},
              {-1,0}};

int Time = 0;
int lastCnt = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
}

int BFS()
{
    memset(visited,false,sizeof visited);
    queue<pii> q;
    q.push({0,0});
    visited[0][0] = true;

    vector<pii> melt;

    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x+dir[i].first;
            int ny = y+dir[i].second;
            if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            if(!map[nx][ny]) q.push({nx,ny});
            else melt.emplace_back(nx,ny);
        }
    }

    if(melt.size() == 0) return 0;

    Time++;
    lastCnt = melt.size();
    for(auto &pos : melt)
        map[pos.first][pos.second] = 0;
    return lastCnt;
}

void SOLVE()
{
    while(BFS());
    cout << Time << " " << lastCnt;
}

int main()
{
    INPUT();
    SOLVE();
}