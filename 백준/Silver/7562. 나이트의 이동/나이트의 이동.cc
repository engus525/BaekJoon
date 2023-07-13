#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int t,n;
int visited[301][301];
typedef pair<int,int> pii;
pii dir[8] = {{-2,1},
              {-1,2},
              {1,2},
              {2,1},
              {2,-1},
              {1,-2},
              {-1,-2},
              {-2,-1}};

void INPUT()
{
    IAMFAST
    cin >> t;
}

void init()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = -1;
}

int BFS(int &sx, int &sy, int &gx, int &gy)
{
    queue<pii> q;
    q.emplace(sx,sy);
    visited[sx][sy] = 0;

    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();

        if(x == gx && y == gy) return visited[x][y];

        for(int i = 0; i < 8; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if(nx < 0 || n <= nx || ny < 0 || n <= ny)
                continue;
            if(visited[nx][ny] != -1) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.emplace(nx,ny);
        }
    }
}

void solution()
{
    while(t--)
    {
        cin >> n;
        init();

        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << BFS(a,b,c,d) << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}