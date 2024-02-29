#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define BASE 1'000'005
#define MOD 1'000'000'000

int n;
int dp[2000020];

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    dp[BASE] = 0, dp[BASE + 1] = 1;
    for (int i = -1; i <= BASE - 2; i++)
        dp[BASE - i - 2] = dp[BASE - i] - dp[BASE - i - 1],
                dp[BASE - i - 2] %= MOD;
    for (int i = 2; i <= BASE; i++)
        dp[BASE + i] = dp[BASE + i - 1] + dp[BASE + i - 2],
                dp[BASE + i] %= MOD;

    int val = dp[BASE + n];
    if (val > 0) cout << 1 << '\n';
    else if (val == 0) cout << 0 << '\n';
    else cout << -1 << '\n';

    cout << abs(val);

}

int main()
{
    INPUT();
    solution();
}