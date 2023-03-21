#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m,t;
int map[51][51];
bool visited[51][51];
pair<int,int> dir[4] = {{0,1},
                        {0,-1},
                        {1,0},
                        {-1,0}};
int noZero = 0;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> map[i][j] , ans += map[i][j];
}

void Turn(int row,int cnt)
{
    int temp[51];

    for(int i = 1; i*row <= n; i++)
    {
        for(int a = 1,b = m-cnt+1; b <= m; a++,b++)
            temp[a] = map[i*row][b];
        for(int a = m; a >= cnt+1; a--)
            map[i*row][a] = map[i*row][a-cnt];
        for(int a = 1; a <= cnt; a++)
            map[i*row][a] = temp[a];
    }
}

bool DFS(int x,int y,bool erase)
{
    if(visited[x][y]) return false;
    visited[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if(ny == m+1) ny = 1;
        if(ny == 0) ny = m;

        if(!(1<=nx&&nx<=n&&1<=ny&&ny<=m)) continue;
        if(map[nx][ny] == 0) continue;
        if(map[x][y] != map[nx][ny]) continue;

        erase = true;
        DFS(nx,ny,true);
    }
    if(erase)
    {
        ans -= map[x][y];
        map[x][y] = 0;
        noZero--;
        return true;
    }
    else return false;
}

void Print()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void SOLVE()
{

    noZero = n*m;

    while(t--)
    {
        //input
        int x,d,k; cin >>x>>d>>k;

        //회전
        if(d == 0) Turn(x,k);
        else Turn(x,m-k);

        //인접 수 삭제
        memset(visited,false,sizeof visited);
        bool erased = false;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(!visited[i][j])
                    if(DFS(i,j,false))
                        erased = true;

        //인접 수가 없다면
        if(!erased)
        {
            int temp = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    if (map[i][j])
                    {
                        if (map[i][j] < ans / double(noZero)) map[i][j]++,temp++;
                        else if (map[i][j] > ans / double(noZero)) map[i][j]--,temp--;
                    }
            ans += temp;
        }

    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}