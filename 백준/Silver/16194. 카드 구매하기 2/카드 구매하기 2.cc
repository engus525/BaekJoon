#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int cost[10001];
int dp[10001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> cost[i];
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = cost[i];
        for (int j = 1; j <= i; j++)
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
    }
    cout << dp[n];
}

int main()
{
    INPUT();
    solution();
}