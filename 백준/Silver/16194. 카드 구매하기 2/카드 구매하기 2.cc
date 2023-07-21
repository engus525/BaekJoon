#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

int n;
int cost[10001];
int dp[1001][1001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> cost[i];
}


void solution()
{
    for (int i = 1; i <= n; i++) dp[1][i] = cost[1] * i;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            dp[i][j] = dp[i-1][j];
            if (j - i >= 0)
                dp[i][j] = min(min(dp[i][j],
                                   dp[i][j - i] + cost[i]),
                               dp[i - 1][j - i] + cost[i]);
        }
    }

    int ans = 2e9;
    for(int i = 1; i <= n; i++) ans = min(ans, dp[i][n]);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}