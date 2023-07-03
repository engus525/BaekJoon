#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, k;
int map[13][13];
deque<int> dq[13][13];
struct Chess
{
    int x, y, d;
};
vector<Chess> v(11);
pair<int, int> dir[4] = {{0,  1},
                         {0,  -1},
                         {-1, 0},
                         {1,  0}};
bool endStatus = false;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    for (int i = 1; i <= k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dq[a][b].emplace_back(i);
        v[i] = {a, b, c - 1};
    }
}

void toWhite(int idx, int nx, int ny)
{
    int x = v[idx].x;
    int y = v[idx].y;

    deque<int> temp;
    while (true)
    {
        int back = dq[x][y].back();
        dq[x][y].pop_back();

        temp.emplace_back(back);
        v[back].x = nx;
        v[back].y = ny;

        if (back == idx) break;
    }

    while (!temp.empty())
    {
        dq[nx][ny].emplace_back(temp.back());
        if (dq[nx][ny].size() >= 4) endStatus = true;
        temp.pop_back();
    }
}

void toRed(int idx, int nx, int ny)
{
    int x = v[idx].x;
    int y = v[idx].y;

    while (true)
    {
        int back = dq[x][y].back();
        dq[x][y].pop_back();

        dq[nx][ny].emplace_back(back);
        if (dq[nx][ny].size() >= 4) endStatus = true;
        v[back].x = nx;
        v[back].y = ny;

        if (back == idx) break;
    }
}

bool cantGo(int x, int y)
{
    return ((x < 1 || n < x || y < 1 || n < y) ||
           map[x][y] == 2);
}

void SOLVE()
{
    int ans = 0;
    while (ans <= 1000)
    {
        ans++;
        for (int i = 1; i <= k; i++)
        {
            int nx = v[i].x + dir[v[i].d].first;
            int ny = v[i].y + dir[v[i].d].second;

            if (cantGo(nx,ny))
            {
                v[i].d = (v[i].d % 2) ? v[i].d - 1 : v[i].d + 1;
                nx = v[i].x + dir[v[i].d].first;
                ny = v[i].y + dir[v[i].d].second;
                if (cantGo(nx,ny)) continue;
            }

            if (map[nx][ny] == 0) toWhite(i, nx, ny);
            else if (map[nx][ny] == 1) toRed(i, nx, ny);

            if (endStatus)
            {
                cout << ans;
                return;
            }
        }

    }

    cout << -1;
}

int main()
{
    INPUT();
    SOLVE();
}