#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
int n,k;
vector<pii> walk(101),bike(101);
int dp[101][100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int a,b,c,d; cin >> a >> b >> c >> d;
        walk[i] = {a,b}; bike[i] = {c,d};
    }
}


void SOLVE()
{
    // Init
    dp[1][walk[1].first] = walk[1].second;
    dp[1][bike[1].first] = bike[1].second;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(dp[i-1][j])
            {
                if(j + walk[i].first <= k)
                {
                    dp[i][j + walk[i].first] =
                            max(dp[i][j + walk[i].first], dp[i-1][j] + walk[i].second);
                }
                if(j + bike[i].first <= k)
                {
                    dp[i][j + bike[i].first] =
                            max(dp[i][j + bike[i].first], dp[i - 1][j] + bike[i].second);
                }
            }
        }
    }

    int ans = -1;
    for(int i = 1; i <= k; i++) ans = max(ans,dp[n][i]);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}