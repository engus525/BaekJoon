#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int R[1001];
int G[1001];
int B[1001];
int dp[3][1001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> R[i] >> G[i] >> B[i];
}


void SOLVE()
{

    int ans = 2e9;
    for(int rgb = 0; rgb < 3; rgb++)
    {

        // Init
        dp[0][1] = 2e9; dp[1][1] = 2e9; dp[2][1] = 2e9;
        if(rgb == 0) dp[0][1] = R[1];
        else if(rgb == 1) dp[1][1] = G[1];
        else dp[2][1] = B[1];
        
        // DP
        for (int i = 2; i <= n; i++)
        {
            dp[0][i] = R[i] + min(dp[1][i - 1], dp[2][i - 1]);
            dp[1][i] = G[i] + min(dp[0][i - 1], dp[2][i - 1]);
            dp[2][i] = B[i] + min(dp[0][i - 1], dp[1][i - 1]);
        }

        // 최솟값 갱신
        for(int i = 0; i < 3; i++)
        {
            if(i == rgb) continue;
            ans = min(ans,dp[i][n]);
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}