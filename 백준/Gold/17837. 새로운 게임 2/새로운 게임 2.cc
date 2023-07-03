#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, k;
int map[13][13];
deque<int> dq[13][13];
typedef pair<int, int> pii;
struct chess
{
    int x, y, d;
};
vector<chess> v(11);
pii dir[4] = {{0,  1},
              {0,  -1},
              {-1, 0},
              {1,  0}};

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
        v[back].x = nx;
        v[back].y = ny;

        if (back == idx) break;
    }
}

bool endStatus()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dq[i][j].size() >= 4)
                return true;
    return false;
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

            if ((nx < 1 || n < nx || ny < 1 || n < ny) ||
                map[nx][ny] == 2)
            {
                v[i].d = (v[i].d % 2) ? v[i].d-1 : v[i].d+1;
                nx = v[i].x + dir[v[i].d].first;
                ny = v[i].y + dir[v[i].d].second;
                if ((nx < 1 || n < nx || ny < 1 || n < ny) ||
                    map[nx][ny] == 2)
                    continue;
            }

            if (map[nx][ny] == 0) toWhite(i, nx, ny);
            else if (map[nx][ny] == 1) toRed(i, nx, ny);

            if (endStatus())
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