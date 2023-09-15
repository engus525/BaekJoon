#include <iostream>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
}

void solution()
{

    while (cin >> n)
    {
        if (n == 0) break;

        ll dp[62][31][31];
        memset(dp, 0, sizeof dp);

        dp[1][n - 1][1] = 1;
        for (int i = 2; i <= 2 * n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    if (j + 1 <= n && k - 1 >= 0 && dp[i - 1][j + 1][k - 1])
                        dp[i][j][k] += dp[i - 1][j + 1][k - 1];
                    if (k + 1 <= n && dp[i - 1][j][k + 1])
                        dp[i][j][k] += dp[i - 1][j][k + 1];
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                ans += dp[2 * n][i][j];
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}