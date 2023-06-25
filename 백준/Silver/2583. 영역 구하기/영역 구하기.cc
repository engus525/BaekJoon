#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int m, n, k;
priority_queue<int, vector<int>, greater<>> ans;
typedef pair<int, int> pii;
pii dir[4] = {{0, -1},
              {0, 1},
              {-1, 0},
              {1,0}};
int map[101][101];
bool visited[101][101];

void INPUT()
{
    IAMFAST
    cin >> m >> n >> k;
    while(k--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int temp = a;
        a = m - b;
        b = temp;
        temp = c;
        c = m - d;
        d = temp;
        for (int i = c; i < a; i++)
            for (int j = b; j < d; j++)
                map[i][j] = 1;
    }
}

void BFS(int sx,int sy)
{
    int size = 1;

    queue<pii> q;
    q.emplace(sx,sy);
    visited[sx][sy] = true;

    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx < 0 || m <= nx || ny < 0 || n <= ny) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny]) continue;

            size++;
            visited[nx][ny] = true;
            q.emplace(nx,ny);
        }
    }
    ans.push(size);
}

void SOLVE()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if(!visited[i][j] && map[i][j] == 0)
                BFS(i,j);

    cout << ans.size() << '\n';
    while(!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}

int main()
{
    INPUT();
    SOLVE();
}