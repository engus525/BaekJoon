#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
char board[51][51];
bool visited[51][51];
pii dir[8] = {{-1, 0},
              {0,  1},
              {1,  0},
              {0,  -1}};
bool ans = false;

void INPUT()
{
    //IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%1s", &board[i][j]);
}

void DFS(int sx, int sy, int x, int y, int size)
{
    visited[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
        if (board[x][y] != board[nx][ny]) continue;
        if (sx == nx && sy == ny && size >= 4)
        {
            ans = true;
            return;
        }
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        DFS(sx,sy,nx,ny,size+1);
    }
}

void solution()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            DFS(i,j,i,j, 1);
            memset(visited,false,sizeof visited);
        }
    if(ans) cout << "Yes";
    else cout << "No";
}

int main()
{
    INPUT();
    solution();
}