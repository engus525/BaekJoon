#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m;
char map[3][3];
bool visited[3][3];
typedef pair<int, int> pii;
pii dir[4] = {{0,  1},
              {0,  -1},
              {-1, 0},
              {1,  0}};

void INPUT()
{
    //IAMFAST
    cin >> n >> m;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%1s", &map[i][j]);
}

bool isOperator(char c)
{
    return (c == '+' || c == '-');
}

int calculate(vector<pii> &pos)
{
    int result = map[pos[0].first][pos[0].second] - '0';
    for (int i = 1; i < 2 * m - 1; i += 2)
    {
        auto [x, y] = pos[i];
        auto [nx, ny] = pos[i + 1];
        if (map[x][y] == '+') result += map[nx][ny] - '0';
        else if (map[x][y] == '-') result -= map[nx][ny] - '0';
    }
    return result;
}

void DFS(int x, int y, int cnt, vector<pii> pos)
{
    if (cnt == 2 * m - 2)
    {
        if (calculate(pos) == n)
        {
            cout << 1 << '\n';
            for (auto &p: pos)
                cout << p.first << " " << p.second << '\n';
            exit(0);
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (nx < 0 || 2 < nx || ny < 0 || 2 < ny) continue;
        if (visited[nx][ny]) continue;
        if (isOperator(map[x][y]) && isOperator(map[nx][ny]))
            continue;
        if (!isOperator(map[x][y]) && !isOperator(map[nx][ny]))
            continue;

        visited[nx][ny] = true;
        pos.emplace_back(nx, ny);
        DFS(nx, ny, cnt + 1, pos);
        visited[nx][ny] = false;
        pos.pop_back();
    }
}

void solution()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!isOperator(map[i][j]))
            {
                memset(visited, false, sizeof visited);
                visited[i][j] = true;
                DFS(i, j, 0, {{i, j}});
            }
    cout << 0;
}

int main()
{
    INPUT();
    solution();
}