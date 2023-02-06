#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int map[101][101];

typedef pair<int, int> pii;
pii dir[4] = {{-1, 0},
              {1,  0},
              {0,  -1},
              {0,  1}};
int visited[101][101];
int ans = 2e9;


void INPUT()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
}

int BFS(int sx, int sy, int a = 0)
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    if (a) map[sx][sy] = a;
    visited[sx][sy] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
            if(visited[nx][ny]) continue;

            if (a && map[nx][ny])//a가 자연수라면 구역 표시
            {
                map[nx][ny] = a;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
            else if(!a)//a가 0이라면 다리 놓기
            {
                //같은 구역이라면 다리 놓을 수 없음
                if (map[sx][sy] == map[nx][ny]) continue;
                if (visited[nx][ny]) continue;

                //0인 구간이라면 다리 설치
                if (!map[nx][ny])
                {
                    visited[nx][ny] = visited[x][y] + 1;
                    if (visited[nx][ny]-2 == ans) return ans;
                    q.push({nx, ny});

                }
                    //다른 구역이라면 다리 연결됨
                else if (map[nx][ny])
                    return visited[x][y] - 1;
            }


        }
    }
    //구역 표시(의미X)
    return 2e9;
}

void SOLVE()
{
    int area = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j] && map[i][j])
                BFS(i, j, area++);
    memset(visited, 0, sizeof visited);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j])
                ans = min(ans,BFS(i,j)),
                memset(visited, 0, sizeof visited);

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}