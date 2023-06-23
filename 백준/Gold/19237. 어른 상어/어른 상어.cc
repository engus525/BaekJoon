#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m, k;
int map[21][21];
typedef pair<int, int> pii;
pii smell[21][21];
pii D[4] = {{-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1}};
pii dir[401][4][4];
struct Shark
{
    int x, y, d;
    bool alive;
};
vector<Shark> shark(401);

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j])
            {
                shark[map[i][j]].x = i;
                shark[map[i][j]].y = j;
                shark[map[i][j]].alive = true;
                smell[i][j] = {map[i][j], k};
            }
        }

    for (int i = 1; i <= m; i++) cin >> shark[i].d, shark[i].d--;

    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 4; j++)
            for (int d = 0; d < 4; d++)
            {
                int num;
                cin >> num;
                num--;
                dir[i][j][d] = D[num];
            }
}

bool inRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

void setPos(int idx, int nx, int ny, pii d)
{
    if (map[nx][ny]) shark[map[nx][ny]].alive = false;
    map[nx][ny] = idx;

    shark[idx].x = nx;
    shark[idx].y = ny;
    for(int i = 0; i < 4; i++)
        if(D[i] == d)
        {
            shark[idx].d = i;
            break;
        }
}

void moveShark()
{
    memset(map, 0, sizeof map);
    for (int i = m; i >= 1; i--)
    {
        if (!shark[i].alive) continue;
        int x = shark[i].x;
        int y = shark[i].y;

        int nx, ny;
        bool moved = false;
        //냄새가 없는 칸
        for (int j = 0; j < 4; j++)
        {
            nx = x + dir[i][shark[i].d][j].first;
            ny = y + dir[i][shark[i].d][j].second;
            if (!inRange(nx, ny)) continue;
            if (smell[nx][ny].second) continue;

            setPos(i, nx, ny, {nx-x,ny-y});
            moved = true;
            break;
        }

        if (moved) continue;

        //자신의 냄새가 있는 칸
        for (int j = 0; j < 4; j++)
        {
            nx = x + dir[i][shark[i].d][j].first;
            ny = y + dir[i][shark[i].d][j].second;
            if (!inRange(nx, ny)) continue;
            if (smell[nx][ny].second == 0) continue;
            if (smell[nx][ny].first != i) continue;

            setPos(i, nx, ny, {nx-x,ny-y});
            break;
        }
    }
}

void smellDown()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (smell[i][j].second)
            {
                smell[i][j].second--;
                if (smell[i][j].second == 0)
                    smell[i][j].first = 0;
            }
}

void smellUp()
{
    for (int i = 1; i <= m; i++)
    {
        if (!shark[i].alive) continue;
        smell[shark[i].x][shark[i].y] = {i, k};
    }
}

int cntShark()
{
    int cnt = 0;
    for (int i = 1; i <= m; i++)
        if (shark[i].alive) cnt++;
    return cnt;
}

void SOLVE()
{
    int ans = 0;
    while (ans <= 1000)
    {
        ans++;

        moveShark();
        smellDown();
        smellUp();

        if (cntShark() == 1) break;
    }

    if (ans <= 1000) cout << ans;
    else cout << -1;
}

int main()
{
    INPUT();
    SOLVE();
}