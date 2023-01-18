#include <iostream>
using namespace std;

int n,k;
int coin[101];
int dp[10'001];

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> coin[i];
}


void SOLVE()
{
    dp[0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(j - coin[i] >= 0)
                dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[k];
}

int main()
{
    INPUT();
    SOLVE();
}
