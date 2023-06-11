#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
char map[11][11];
typedef pair<int,int> pii;
pii dir[4] = {{-1,0},
              {1,0},
              {0,-1},
              {0,1}};
pii rPos,bPos,hPos;
bool visited[11][11][11][11];

void INPUT()
{
    //IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            scanf("%1s",&map[i][j]);
            if(map[i][j] == 'R') rPos = {i,j}, map[i][j] = '.';
            else if(map[i][j] == 'B') bPos = {i,j}, map[i][j] = '.';
            else if(map[i][j] == 'O') hPos = {i,j};
        }
}

bool rFirst(pii r,pii b,int d)
{
    if(d == 0) return r.first <= b.first;
    else if(d == 1) return r.first >= b.first;
    else if(d == 2) return r.second <= b.second;
    else return r.second >= b.second;
}

void moveR(pii &r,pii b,int d)
{
    while(true)
    {
        int nx = r.first + dir[d].first;
        int ny = r.second + dir[d].second;
        if(r == hPos) break;
        if(map[nx][ny] == '#') break;
        if(nx == b.first && ny == b.second && map[nx][ny] == '.') break;
        r = {nx,ny};
    }
}

void moveB(pii &b,pii r,int d)
{
    while(true)
    {
        int nx = b.first + dir[d].first;
        int ny = b.second + dir[d].second;
        if(b == hPos) break;
        if(map[nx][ny] == '#') break;
        if(nx == r.first && ny == r.second && map[nx][ny] == '.') break;
        b = {nx,ny};
    }
}

void Print(pii r,pii b, int cnt)
{
    cout << "==========\n";
    cout << "R : (" << r.first << "," << r.second << ")\n";
    cout << "B : (" << b.first << "," << b.second << ")\n";
    cout << "cnt : " << cnt << '\n';
}

int BFS()
{
    queue<pair<pair<pii,pii>,int>> q;
    q.push({{rPos,bPos},0});
    visited[rPos.first][rPos.second][bPos.first][bPos.second] = true;

    while(!q.empty())
    {
        pii r = q.front().first.first;
        pii b = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(cnt > 10) return -1;
        if(b == hPos) continue;
        if(r == hPos) return cnt;

        pii copyR = r, copyB = b;
        for(int i = 0; i < 4; i++)
        {
            if(rFirst(r,b,i))
            {
                moveR(r,b,i);
                moveB(b,r,i);
            }
            else
            {
                moveB(b,r,i);
                moveR(r,b,i);
            }
            if(r == copyR && b == copyB) continue;
            if(visited[r.first][r.second][b.first][b.second])
            {
                r = copyR;
                b = copyB;
                continue;
            }
            visited[r.first][r.second][b.first][b.second] = true;
            q.push({{r,b},cnt+1});
            r = copyR;
            b = copyB;
        }
    }
    return -1;
}

void SOLVE()
{
    cout << BFS();
}

int main()
{
    INPUT();
    SOLVE();
}