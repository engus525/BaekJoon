#include <iostream>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
bool visited[35][35];
double per[4];
typedef pair<int,int> pii;
pii dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
double ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < 4; i++) cin >> per[i], per[i] /= 100.0;
}

void DFS(int x,int y, int mov,double p)
{
    if(mov == n)
    {
        ans += p;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if(visited[nx][ny]) continue;

        visited[nx][ny] = true;
        DFS(nx,ny,mov+1,p*per[i]);
        visited[nx][ny] = false;
    }
}

void SOLVE()
{
    visited[15][15] = true;
    DFS(15,15,0,1);
    
    cout << fixed;
    cout.precision(9);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}