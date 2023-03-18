#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // cpp
#include <stdio.h> // c
#include <string>
#include <memory.h> // memset
#include <algorithm>
#include <cmath>
// 자료 구조
#include <queue>
#include <vector>
#include <stack>
#include <set>
//#include <map>
using namespace std;

int r, c;
int map[10001][501];
int dir[3][2] = { {-1,1},{0,1},{1,1} }; // 오른쪽 위 대각, 오른쪽, 오른쪽 아래 대각

int ans = 0;

void INPUT()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            scanf("%1s", &map[i][j]);

}

bool DFS(int row, int col)
{
    int x = row, y = col;

    // 원웅이 빵집에 도달했다면
    if (col == c && map[x][y] == '.')
    {
        ans++;
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (1 <= nx && nx <= r && 1 <= ny && ny <= c)
        {
            if (map[nx][ny] == '.' && DFS(nx, ny))
            {
                map[nx][ny] = 'x';
                return true;
            }
            // 가지치기 : 이 경로를 통해 연결할 수 없음
            else map[nx][ny] = 'x';
        }
    }
    // 원웅이 빵집에 연결할 수 없다면
    return false;
}

void SOLVE()
{
    for (int i = 1; i <= r; i++) DFS(i, 1);

    cout << ans;
}



int main()
{
    INPUT();

    SOLVE();

}

