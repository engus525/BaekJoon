#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t;
int dp[1000001];
#define MOD 1'000'000'009

void INPUT()
{
    IAMFAST
    cin >> t;
}


void SOLVE()
{
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4; i <= 1000000; i++)
    {
        dp[i] = ((dp[i-1] + dp[i-2]) % MOD + dp[i-3]) % MOD;
    }

    while(t--)
    {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}