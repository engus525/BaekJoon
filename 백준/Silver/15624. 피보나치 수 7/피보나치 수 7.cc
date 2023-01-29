#include <iostream>
using namespace std;

int n;
int dp[1000001];
#define MOD 1000000007

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
}


void SOLVE()
{
    dp[0] = 0; dp[1] = 1; dp[2] = 1;

    for(int i = 3; i <= n; i++) dp[i] = dp[i-1]%MOD + dp[i-2]%MOD,dp[i] %= MOD;
    cout << dp[n];
}

int main()
{
    INPUT();
    SOLVE();
}