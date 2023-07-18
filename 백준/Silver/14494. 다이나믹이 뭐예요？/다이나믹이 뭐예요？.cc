#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int dp[1001][1001];
#define MOD 1'000'000'007

void INPUT()
{
    IAMFAST
    cin >> n >> m;
}

void solution()
{
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!dp[i][j])
                dp[i][j] = ((dp[i - 1][j] % MOD +
                            dp[i][j - 1] % MOD) % MOD +
                            dp[i - 1][j - 1] % MOD) % MOD;
    cout << dp[n][m];
}

int main()
{
    INPUT();
    solution();
}