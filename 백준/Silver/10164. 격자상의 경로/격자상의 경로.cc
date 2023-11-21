#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, k;
int dp[16][16];

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
}

void solution()
{
    for (int i = 2; i <= n; i++) dp[i][1] = 1;
    for (int i = 2; i <= m; i++) dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    int xIdx = (k / (m+1)) + 1;
    int yIdx = ((k-1) % m) + 1;

    if (k == 0) cout << dp[n][m];
    else cout << dp[xIdx][yIdx] * dp[n - xIdx + 1][m - yIdx + 1];
}

int main()
{
    INPUT();
    solution();
}