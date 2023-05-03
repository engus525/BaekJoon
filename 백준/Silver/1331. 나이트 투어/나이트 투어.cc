#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n = 36;
int visited[8][8];
pair<int, int> dir[8] = {{2,  1},
                         {2,  -1},
                         {1,  2},
                         {1,  -2},
                         {-1, -2},
                         {-1, 2},
                         {-2, 1},
                         {-2, -1}};
int sx = -1, sy = -1;
int fx = -1, fy = -1;

void INPUT()
{
    IAMFAST
}


void SOLVE()
{
    int cnt = 1;
    while (n--)
    {
        string str;
        cin >> str;
        int x = 7 - (str[1] - '0'), y = str[0] - 'A' + 1;

        bool isNight = false;
        for (auto [a, b]: dir)
                if((fx+a == x && fy+b == y) || sx == -1)
                    isNight = true;
        if(!isNight) break;

        if (sx == -1) sx = x, sy = y;
        fx = x, fy = y;

        visited[x][y] = cnt++;
    }

    bool visitedAll = true;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            if (!visited[i][j])
                visitedAll = false;

    bool canBack = false;
    for (auto [x, y]: dir)
    {
        int nx = fx + x, ny = fy + y;
        if (nx < 1 || 6 < nx || ny < 1 || 6 < ny) continue;
        if (visited[nx][ny] == 1) canBack = true;
    }

    if (visitedAll && canBack) cout << "Valid";
    else cout << "Invalid";

}

int main()
{
    INPUT();
    SOLVE();
}