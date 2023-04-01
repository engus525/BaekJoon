#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
int t;
ll dp[10][65];
ll ans[65];

void INPUT()
{
    IAMFAST
    cin >> t;
}

void DP()
{
    for(int i = 0; i < 10; i++) dp[i][1] = 1;
    ans[1] = 10;

    ll ps = 10;
    for(int i = 2; i <= 64; i++)
    {
        dp[0][i] = ps;

        ps = dp[0][i];
        for(int j = 1; j < 10; j++)
        {
            dp[j][i] = dp[j-1][i] - dp[j-1][i-1];
            ps += dp[j][i];
        }
        ans[i] = ps;
    }
}

void SOLVE()
{
    DP();
    while(t--)
    {
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}