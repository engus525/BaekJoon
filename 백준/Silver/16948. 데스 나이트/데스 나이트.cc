#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int visited[201][201];
int sx, sy, gx, gy;
typedef pair<int, int> pii;
pii dir[6] = {{-2, -1},
              {-2, 1},
              {0,  -2},
              {0,  2},
              {2,  -1},
              {2,  1}};

void INPUT()
{
    IAMFAST
    cin >> n;
    cin >> sx >> sy >> gx >> gy;
}

void BFS()
{

    queue<pii> q;
    q.emplace(sx, sy);
    visited[sx][sy] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if(x == gx && y == gy) return;

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || n <= nx || ny < 0 || n <= ny)
                continue;
            if (visited[nx][ny] != -1) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.emplace(nx, ny);
        }
    }

}

void solution()
{
    memset(visited, -1, sizeof visited);
    BFS();
    cout << visited[gx][gy];
}

int main()
{
    INPUT();
    solution();
}