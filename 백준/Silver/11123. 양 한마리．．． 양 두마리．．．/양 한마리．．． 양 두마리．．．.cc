#include <iostream>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
int n, m;
char graph[101][101];
bool visited[101][101];
pii dir[8] = {{-1, 0},
              {0,  1},
              {1,  0},
              {0,  -1}};

void INPUT()
{
    //IAMFAST
    cin >> t;
}

void DFS(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (graph[nx][ny] == '.') continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        DFS(nx, ny);
    }
}

void solution()
{
    while(t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%1s", &graph[i][j]);
        memset(visited, false, sizeof visited);

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!visited[i][j] && graph[i][j] == '#')
                    ans++, DFS(i,j);

        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}