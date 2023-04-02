#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int map[1001][1001];
int dp[1001][1001];
int ans = 0;

void INPUT()
{
   //IAMFAST
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%1d",&map[i][j]);
}


void SOLVE()
{

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(map[i][j])
            {
                dp[i][j] = min(min(dp[i - 1][j],
                                   dp[i - 1][j - 1]),
                               dp[i][j - 1]) + 1;
                ans = max(ans,dp[i][j]);
            }
    cout << ans*ans;

}

int main()
{
    INPUT();
    SOLVE();
}