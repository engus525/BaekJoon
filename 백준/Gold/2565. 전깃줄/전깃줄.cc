#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> wire;
int dp[101];

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b; cin >> a >> b;
        wire.push_back({a,b});
    }
}


void SOLVE()
{
    sort(wire.begin(),wire.end());
    dp[0] = 1;

    int longest = 1;
    for(int i = 1; i < n; i++)
    {
        int temp = 1;
        for(int j = 0; j < i; j++)
        {
            if(wire[j].second < wire[i].second)
            {
                temp = max(temp, dp[j] + 1);
            }
        }
        dp[i] = temp;
        longest = max(longest,dp[i]);
    }

    cout << n - longest;

}

int main()
{
    INPUT();
    SOLVE();
}
