#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int dp[46];

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    dp[0]=0;dp[1]=1;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1]+dp[i-2];
    cout << dp[n];
}

int main()
{
    INPUT();
    SOLVE();
}