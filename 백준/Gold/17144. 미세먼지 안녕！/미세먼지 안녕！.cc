#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
int r,c,t;
int map[51][51],added[51][51];
vector<pii> cleaner;
queue<pii> dust;
pii dir[4] = {{0,-1},{0,1},{-1,0},{1,0}};

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == -1) cleaner.push_back({i,j});
            else if(map[i][j] > 0) dust.push({i,j});

        }
}

void Spread()
{
    for(int x = 0; x < r; x++)
        for(int y = 0; y < c; y++)
        {
            if(map[x][y] <= 0) continue;

            int spreadCnt = 0; //확산된 방향 갯수
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;


                if(0 <= nx && nx < r && 0 <= ny && ny < c)
                {
                    if(map[nx][ny] == -1) continue; // 공기청정기 확산x
                    spreadCnt++;
                    added[nx][ny] += map[x][y]/5;
                }
            }
            // 먼지 양 갱신
            map[x][y] -= map[x][y]/5 * spreadCnt;
        }

    // 먼지 양 갱신
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            map[i][j] += added[i][j];
}

void Clean()
{
    // 위 공기청정기
    int x = cleaner[0].first, y = cleaner[0].second;
    for(int i = x-1; i > 0; i--) map[i][0] = map[i-1][0];
    for(int i = 0; i < c-1; i++) map[0][i] = map[0][i+1];
    for(int i = 0; i < x; i++) map[i][c-1] = map[i+1][c-1];
    for(int i = c-1; i > 1; i--) map[x][i] = map[x][i-1];
    map[x][y+1] = 0;

    // 아래 공기청정기
    x = cleaner[1].first; y = cleaner[1].second;
    for(int i = x+1; i < r-1; i++) map[i][0] = map[i+1][0];
    for(int i = 0; i < c-1; i++) map[r-1][i] = map[r-1][i+1];
    for(int i = r-1; i > x; i--) map[i][c-1] = map[i-1][c-1];
    for(int i = c-1; i > 1; i--) map[x][i] = map[x][i-1];
    map[x][y+1] = 0;
}

void SOLVE()
{
    while(t--)
    {
        memset(added,0,sizeof added);
        Spread();
        Clean();
    }

    int ans = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(map[i][j] > 0) ans += map[i][j];
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}