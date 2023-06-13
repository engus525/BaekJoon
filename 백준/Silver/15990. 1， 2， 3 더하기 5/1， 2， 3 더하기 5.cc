#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t;
int dp[100001][4];
#define MOD 1'000'000'009

void INPUT()
{
    IAMFAST
    cin >> t;
}


void SOLVE()
{
    dp[1][1] = 1, dp[1][2] = 0, dp[1][3] = 0;
    dp[2][1] = 0, dp[2][2] = 1, dp[2][3] = 0;
    dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;

    for(int i = 4; i <= 100000; i++)
    {
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
    }


    while(t--)
    {
        int n; cin >> n;
        int ans = (((dp[n][1] + dp[n][2]) % MOD) + dp[n][3]) % MOD;
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}