#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int dp[41];

void INPUT()
{
    IAMFAST
    cin >> n;
}

int fib(int x, int &cnt)
{
    if (x <= 2)
    {
        cnt++;
        return 1;
    }
    else return fib(x-1,cnt)+fib(x-2,cnt);
}


void SOLVE()
{
    dp[5] = 5; dp[6] = 8;
    for(int i = 7; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    cout << dp[n] << " " << n-2;
}

int main()
{
    INPUT();
    SOLVE();
}