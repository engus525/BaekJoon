#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
ll list[101];
ll dp[101][21];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> list[i];
}

void solution()
{
    dp[1][list[1]] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (j - list[i] >= 0 && dp[i - 1][j - list[i]])
                dp[i][j] += dp[i - 1][j - list[i]];
            if (j + list[i] <= 20 && dp[i - 1][j + list[i]])
                dp[i][j] += dp[i - 1][j + list[i]];
        }
    }

    cout << dp[n - 1][list[n]];
}

int main()
{
    INPUT();
    solution();
}