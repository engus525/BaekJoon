#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int r, c, k, sx, sy;
int graph[1001][1001];
bool visited[1001][1001];
pii dir[4] = {{-1, 0},
              {1,  0},
              {0,  -1},
              {0,  1}};
int D[4];
int dIdx = 0;

void INPUT()
{
    IAMFAST
    cin >> r >> c >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;//장애물
    }
    cin >> sx >> sy;
    for (int i = 0; i < 4; i++)
    {
        int d; cin >> d;
        D[i] = d - 1;
    }
}


void solution()
{
    int x = sx, y = sy;
    visited[x][y] = true;

    while(true)
    {
        int nx, ny;

        //이동 방향 설정
        bool canMove = false;
        for (int i = 0; i < 4; i++)
        {
            int nd = (dIdx + i) % 4;
            nx = x + dir[D[nd]].first;
            ny = y + dir[D[nd]].second;

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited[nx][ny]) continue;
            if (graph[nx][ny]) continue;

            canMove = true;
            visited[nx][ny] = true;
            x = nx, y = ny;
            dIdx = nd;
            break;
        }

        if (!canMove) break;
    }

    cout << x << " " << y;
}

int main()
{
    INPUT();
    solution();
}