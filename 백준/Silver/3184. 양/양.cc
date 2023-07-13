#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m;
char map[251][251];
bool visited[251][251];
typedef pair<int, int> pii;
pii dir[4] = {{0,  1},
              {0,  -1},
              {1,  0},
              {-1, 0}};
int oCnt = 0, vCnt = 0;

void INPUT()
{
    //IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%1s",&map[i][j]);
            if(map[i][j] == 'o') oCnt++;
            else if(map[i][j] == 'v') vCnt++;
        }
}

void BFS(int sx,int sy)
{
    int o = 0, v = 0;

    queue<pii> q;
    q.emplace(sx,sy);
    visited[sx][sy] = true;

    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();

        if(map[x][y] == 'o') o++;
        else if(map[x][y] == 'v') v++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx < 0 || n <= nx || ny < 0 || m <= ny)
                continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] == '#') continue;

            visited[nx][ny] = true;
            q.emplace(nx,ny);
        }
    }

    if(o > v) vCnt -= v;
    else oCnt -= o;
}

void solution()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(!visited[i][j] && map[i][j] != '#')
                BFS(i,j);
    cout << oCnt << " " << vCnt;
}

int main()
{
    INPUT();
    solution();
}