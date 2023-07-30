#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int l,r,c;
char graph[31][31][31];
int visited[31][31][31];
struct Pos
{
    int x, y, z;
};
Pos dir[6] = {{0,  -1, 0},
              {0,  0,  1},
              {0,  1,  0},
              {0,  0,  -1},
              {1,  0,  0},
              {-1, 0,  0}};
Pos start;

void BFS()
{
    queue<Pos> q;
    q.emplace(start);
    visited[start.x][start.y][start.z] = 1;

    while (!q.empty())
    {
        auto [x, y,z] = q.front();
        q.pop();

        if (graph[x][y][z] == 'E')
        {
            cout << "Escaped in " << visited[x][y][z] - 1 << " minute(s).\n";
            return;
        }

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dir[i].x;
            int ny = y + dir[i].y;
            int nz = z + dir[i].z;
            if (nx < 0 || ny < 0 || nz < 0 || l <= nx || r <= ny || c <= nz) continue;
            if (visited[nx][ny][nz]) continue;
            if (graph[nx][ny][nz] == '#') continue;

            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }

    cout << "Trapped!\n";
}

int main()
{
    while(cin >> l >> r >> c)
    {
        if (l == 0 ) break;

        memset(visited, 0, sizeof visited);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++)
                for (int k = 0; k < c; k++)
                {
                    scanf("%1s", &graph[i][j][k]);
                    if (graph[i][j][k] == 'S') start = {i,j,k};
                }

        BFS();
    }
}
