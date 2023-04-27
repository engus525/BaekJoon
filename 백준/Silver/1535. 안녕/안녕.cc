#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int L[21], J[21];
int dp[21][101];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> L[i];
    for(int i = 1; i <= n; i++) cin >> J[i];
}


void SOLVE()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < 100; j++)
        {
            if(j < L[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-L[i]]+J[i]);
        }
    cout << dp[n][99];
}

int main()
{
    INPUT();
    SOLVE();
}