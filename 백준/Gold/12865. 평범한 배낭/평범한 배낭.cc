#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
int n,k;
vector<pii> obj;
int dp[101][100'001];

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    obj.push_back({0,0});
    for(int i = 0; i < n; i++)
    {
        int w, v; cin >> w >> v;
        obj.push_back({w,v});
    }
}


void SOLVE()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(j - obj[i].first < 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],
                                dp[i-1][j-obj[i].first] + obj[i].second);
        }
    }
    cout << dp[n][k];
}

int main()
{
    INPUT();
    SOLVE();
}
