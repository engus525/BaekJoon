#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m;
int jew[100001];
int ps[100001];
int dp[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> jew[i],
        ps[i] = jew[i] + ps[i-1];
}


void SOLVE()
{
    for(int i = 1; i < m; i++) dp[i] = ps[i];

    int ans = 0;
    for(int i = m; i <= n; i++)
    {
        dp[i] = max(dp[i-1] + jew[i], ps[i] - ps[i - m]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}