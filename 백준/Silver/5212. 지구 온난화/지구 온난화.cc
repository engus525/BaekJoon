#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef pair<int, int> pii;

int r, c;
char graph[11][11];
vector<pii> v;
pii dir[4] = {{0,  -1},
              {0,  1},
              {-1, 0},
              {1,  0}};
int le = 10, ri = 0, up = 10, down = 0;

void INPUT()
{
    //IAMFAST
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            scanf("%1s", &graph[i][j]);
}

void setLinePos(int x, int y)
{
    le = min(le, y);
    ri = max(ri, y);
    up = min(up, x);
    down = max(down, x);
}

void saveLivePos()
{
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            if (graph[i][j] == '.') continue;

            int cnt = 0;
            for (auto &d: dir)
            {
                int nx = i + d.first, ny = j + d.second;

                if (nx < 1 || nx > r || ny < 1 || ny > c) cnt++;
                else if (graph[nx][ny] == '.') cnt++;
            }

            if (cnt >= 3) v.emplace_back(i, j);
        }
}

void solution()
{
    saveLivePos();

    for (auto p: v) graph[p.first][p.second] = '.';

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (graph[i][j] == 'X')
                setLinePos(i, j);

    for (int i = up; i <= down; i++)
    {
        for (int j = le; j <= ri; j++)
            cout << graph[i][j];
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}