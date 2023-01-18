#include <iostream>
using namespace std;

#define MOD 9901
int n;
int dp[100'001];

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
}


void SOLVE()
{
    dp[0] = 1; dp[1] = 3;

    for(int i = 2; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1]) % MOD + dp[i - 2] % MOD;
        dp[i] %= MOD;
    }

    cout << dp[n];
}

int main()
{
    INPUT();
    SOLVE();
}
