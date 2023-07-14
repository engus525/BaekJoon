#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m;
char map[101][101];
bool visited[101][101];
typedef pair<int, int> pii;
pii dir[4] = {{0,  1},
              {0,  -1},
              {1,  0},
              {-1, 0}};
int bSum = 0, wSum = 0;

void INPUT()
{
    //IAMFAST
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1s",&map[i][j]);
}

void BFS(int sx, int sy)
{
    int b = 0, w = 0;

    queue<pii> q;
    q.emplace(sx, sy);
    visited[sx][sy] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if(map[x][y] == 'W') w++;
        else b++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || n <= nx || ny < 0 || m <= ny)
                continue;
            if (map[nx][ny] != map[x][y]) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }

    bSum += b*b;
    wSum += w*w;
}

void solution()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j])
                BFS(i,j);

    cout << wSum << " " << bSum;
}

int main()
{
    INPUT();
    solution();
}