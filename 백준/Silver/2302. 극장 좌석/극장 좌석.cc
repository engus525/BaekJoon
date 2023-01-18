#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<pair<int,int>> dp(41);
bool fix[42];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int seat; cin >> seat;
        fix[seat] = true;
    }fix[n + 1] = true;
}


void SOLVE()
{
    dp[0] = {1,0}; dp[1] = {0,1};

    for(int i = 2; i <= n; i++)
    {
        if(!(fix[i-1] || fix[i]))
            dp[i] = {dp[i-2].first+dp[i-1].first,
                     dp[i-2].second+dp[i-1].second};
        else dp[i] = dp[i-1];
    }

    cout << dp[n].first + dp[n].second;

}

int main()
{
    INPUT();
    SOLVE();
}