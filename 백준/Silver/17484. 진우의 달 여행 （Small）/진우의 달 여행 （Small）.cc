#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m;
int map[7][7];
int dp[7][7][4];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            for(int k = 0; k < 4; k++)
                dp[i][j][k] = 2e9;
        }
}

int DP(int x, int y, int d)
{
    if (x == n) return 0;
    if (dp[x][y][d] != 2e9) return dp[x][y][d];

    if (d != 0 && 0 <= y - 1)
        dp[x][y][d] = DP(x + 1, y - 1, 0) + map[x][y];
    if (d != 1)
        dp[x][y][d] = min(dp[x][y][d], DP(x + 1, y, 1) + map[x][y]);
    if (d != 2 && y + 1 < m)
        dp[x][y][d] = min(dp[x][y][d], DP(x + 1, y + 1, 2) + map[x][y]);

    return dp[x][y][d];
}

void SOLVE()
{
    int ans = 2e9;
    for (int i = 0; i < m; i++)
        ans = min(ans, DP(0, i, 3));
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}