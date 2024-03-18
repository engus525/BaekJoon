#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
ll dp[101];

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    dp[1] = 1, dp[2] = 2, dp[3] = 3;
    for (ll i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 3; i - j >= 1; j++)
            dp[i] = max(dp[i], dp[i - j] * (j - 1));
        //cout << i << " : " << dp[i] << "\n";
    }
    cout << dp[n];
}

int main()
{
    INPUT();
    solution();
}