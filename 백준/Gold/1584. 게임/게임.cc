#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int a,b,c,d;
int map[501][501];
int dist[501][501];
bool visited[501][501];
typedef pair<int,int> pii;
pii dir[4] = {{1,0},
              {-1,0},
              {0,1},
              {0,-1}};

void INPUT()
{
    IAMFAST
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> c >> d;
        for (int i = min(a,c); i <= max(a,c); i++)
            for (int j = min(b,d); j <= max(b,d); j++)
                map[i][j] = 1;
    }
    cin >> m;
    while(m--)
    {
        cin >> a >> b >> c >> d;
        for (int i = min(a,c); i <= max(a,c); i++)
            for (int j = min(b,d); j <= max(b,d); j++)
                map[i][j] = 2;
    }
}

void ijk()
{
    fill(&dist[0][0],&dist[500][501],2e9);
    deque<pair<pii,int>> dq;
    dq.push_back({{0,0},0});
    dist[0][0] = 0;

    while(!dq.empty())
    {
        auto [x, y] = dq.front().first;
        int d1 = dq.front().second;
        dq.pop_front();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx<0 || 500<nx || ny<0 || 500<ny) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny] == 2) continue;
            int d2 = map[nx][ny];

            visited[nx][ny] = true;
            dist[nx][ny] = d1+d2;
            if(d2) dq.push_back({{nx,ny},d1+d2});
            else dq.push_front({{nx,ny},d1+d2});
        }
    }
}

void SOLVE()
{
    ijk();
    if(dist[500][500] == 2e9) cout << -1;
    else cout << dist[500][500];
}

int main()
{
    INPUT();
    SOLVE();
}