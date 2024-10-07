#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include <memory.h>
#include <set>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int r, c;
char graph[11][11];
pii dir[4] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0}
};

void INPUT()
{
    IAMFAST
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++)
            graph[i][j] = str[j];
    }
}

bool isBlocked(int x, int y)
{
    int passCnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (nx == x && ny == y) continue;
        if (graph[nx][ny] == 'X') continue;

        passCnt++;
    }

    return passCnt < 2;
}

void solution()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (graph[i][j] == 'X') continue;
            if (isBlocked(i, j))
            {
                cout << 1;
                return;
            }
        }
    }
    cout << 0;
}

int main()
{
    INPUT();
    solution();
}