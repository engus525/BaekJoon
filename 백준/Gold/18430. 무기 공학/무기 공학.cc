#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int map[6][6];
bool visited[6][6];
pair<int,int> dir[4] = {{-1,0},
                        {0,1},
                        {1,0},
                        {0,-1}};
int ans = 0;


void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
}

bool OutRange(int a,int b,int c,int d)
{
    if(a < 0 || n <= a || b < 0 || m <= b) return true;
    if(c < 0 || n <= c || d < 0 || m <= d) return true;
    return false;
}

void DFS(int x,int y,int score)
{

    visited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx1 = x + dir[i].first;
        int ny1 = y + dir[i].second;
        int nx2 = x + dir[(i+1)%4].first;
        int ny2 = y + dir[(i+1)%4].second;
        if(OutRange(nx1,ny1,nx2,ny2)) continue;
        if(visited[nx1][ny1] || visited[nx2][ny2]) continue;

        int boomerang = 2 * map[x][y] + map[nx1][ny1] + map[nx2][ny2];

        visited[nx1][ny1] = true;
        visited[nx2][ny2] = true;

        bool init = false;
        for(int a = 0; a < n; a++)
            for(int b = 0; b < m; b++)
            {
                if(!init) a = x,b = y,init = true;
                if (!visited[a][b])
                    DFS(a, b,score+boomerang);
            }
        ans = max(ans,score+boomerang);

        visited[nx1][ny1] = false;
        visited[nx2][ny2] = false;

    }
    visited[x][y] = false;
}

void SOLVE()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!visited[i][j])
                DFS(i,j,0);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
