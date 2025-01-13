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
typedef pair<long long, long long> pll;

int n;
int taste[1001];
int dp[1001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> taste[i];
}

void solution()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!dp[i]) dp[i] = taste[i];
        for (int j = 1; j < i; j++)
        {
            if (taste[j] < taste[i]) dp[i] = max(dp[i], dp[j] + taste[i]);
        }
        ans = max(ans, dp[i]);
    }
//    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << ans;
}


int main()
{
    INPUT();
    solution();
}