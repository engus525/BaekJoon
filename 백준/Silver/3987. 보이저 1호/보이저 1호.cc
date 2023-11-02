#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
char graph[501][501];
int visited[501][501][4];
pii dir[4] = {{-1, 0},
              {0,  1},
              {1,  0},
              {0,  -1}};
struct POS
{
    pii pos;
    int dir;
};
POS start;

void INPUT()
{
    //IAMFAST
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1s", &graph[i][j]);
    cin >> start.pos.first >> start.pos.second;
}

int changeDir(int d, char value)
{
    if (value == '.') return d;

    if (value == '\\')
    {
        if (d == 2) d = 1;
        else if (d == 3) d = 0;
        else if (d == 1) d = 2;
        else if (d == 0) d = 3;
    } else if (value == '/')
    {
        if (d == 0) d = 1;
        else if (d == 3) d = 2;
        else if (d == 1) d = 0;
        else if (d == 2) d = 3;
    }
    return d;
}

int BFS()
{
    int timer = 0;

    queue<POS> q;
    q.emplace(start);
    visited[start.pos.first][start.pos.second][start.dir] = 1;

    while (!q.empty())
    {
        auto [p, d] = q.front();
        auto [x, y] = p;
        q.pop();

        POS next = {{x + dir[d].first, y + dir[d].second}, d};
        auto [nx, ny] = next.pos;
        if (nx < 1 || nx > n || ny < 1 || ny > m) return timer;
        if (graph[nx][ny] == 'C') return timer;

        next.dir = changeDir(d, graph[nx][ny]);
        if (visited[nx][ny][next.dir]) return 2e9;

        visited[next.pos.first][next.pos.second][next.dir] = visited[x][y][d] + 1;
        timer = max(timer, visited[next.pos.first][next.pos.second][next.dir]);
        q.emplace(next);

    }
    return timer;
}

void solution()
{
    int timer = 0;
    int ansD = 0;
    for (int d = 0; d <= 3; d++)
    {
        memset(visited, 0, sizeof visited);
        start.dir = d;
        int temp = BFS();
        if (temp > timer) timer = temp, ansD = d;
    }

    if (ansD == 0) cout << "U";
    else if (ansD == 1) cout << "R";
    else if (ansD == 2) cout << "D";
    else if (ansD == 3) cout << "L";
    cout << '\n';
    if (timer == 2e9) cout << "Voyager";
    else cout << timer;
}

int main()
{
    INPUT();
    solution();
}