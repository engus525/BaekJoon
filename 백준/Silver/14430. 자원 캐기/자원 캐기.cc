#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int map[301][301];
int dp[301][301];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> map[i][j];
}


void SOLVE()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + map[i][j];
    cout << dp[n][m];
}

int main()
{
    INPUT();
    SOLVE();
}