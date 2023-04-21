#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,k,r;
int map[101][101];
typedef pair<int,int> pii;
vector<pii> road[101][101];
bool visited[101][101];
pii dir[4] = {{0,1},
              {0,-1},
              {1,0},
              {-1,0}};


void INPUT()
{
    IAMFAST
    cin >> n >> k >> r;
    for(int i = 0; i < r; i++)
    {
        int a,b,c,d; cin>>a>>b>>c>>d;
        road[a][b].emplace_back(c,d);
        road[c][d].emplace_back(a,b);
    }
    for(int i = 0; i < k; i++)
    {
        int a,b; cin >> a >> b;
        map[a][b] = 1;
    }
}

int BFS(int sx,int sy)
{
    int canMeet = 0;

    memset(visited,false,sizeof visited);
    visited[sx][sy] = true;

    queue<pii> q;
    q.push({sx,sy});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            //범위 초과
            if(nx < 1 || n < nx || ny < 1 || n < ny) continue;
            //이미 방문한 지점
            if(visited[nx][ny]) continue;
            //길
            bool notRoad = true;
            for(auto [a,b] : road[x][y])
                if(a==nx && b==ny)
                    notRoad = false;
            if(!notRoad) continue;


            if(map[nx][ny] == 1) canMeet++;
            visited[nx][ny] = true;
            q.push({nx,ny});
        }

    }
    return canMeet;
}


void SOLVE()
{
    int ans = 0,cnt = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(map[i][j] == 1)
                ans += k - cnt - BFS(i,j),
                cnt++,
                map[i][j] = -1;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
