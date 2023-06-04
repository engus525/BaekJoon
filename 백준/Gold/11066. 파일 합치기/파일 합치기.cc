#include <iostream>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t, n;
int file[501];
int ps[501];
int dp[501][501];
int ans = 2e9;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void init()
{
    ans = 2e9;
    for(int i = 1; i <= 501; i++) file[i] = 0,ps[i] = 0;
    memset(dp,0,sizeof dp);
}

void SOLVE()
{
    while(t--)
    {
        init();
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> file[i],ps[i] = ps[i-1]+file[i];

        //dp
        for(int range = 1; range < n; range++)
        {
            for(int idx = 1; range+idx <= n; idx++)
            {
                dp[idx][range+idx] = 2e9;
                for(int cri = 0; cri < range; cri++)
                {
                    int left = (dp[idx][idx+cri]);
                    int right = (dp[idx+cri+1][range+idx]);

                    dp[idx][range+idx] = min(dp[idx][range+idx],
                                             left+right+ps[range+idx]-ps[idx-1]);
                }
            }
        }

        cout << dp[1][n] << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}