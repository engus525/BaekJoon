#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
ll dp[120];

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    for (int i = 1; i < 4; i++) dp[i] = 1;

    for (int i = 4; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 3];

    cout << dp[n];
}

int main()
{
    INPUT();
    solution();
}