#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int dp[21];

void INPUT()
{
    IAMFAST
    cin >> n;
}


void SOLVE()
{
    dp[1] = 1; dp[2] = 2; dp[3] = 4; dp[4] = 7;
    for(int i = 5; i <= 20; i++)
    {
        if(i % 2) dp[i] = 2*dp[i-1];
        else dp[i] = 2*dp[i-1] - dp[i-5] - dp[i-4];
    }
    cout << dp[n];
}

int main()
{
    INPUT();
    SOLVE();
}
