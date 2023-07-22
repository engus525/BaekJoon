#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int dp[1002][1002];

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    dp[1][0] = 1;
    for (int i = 1; i <= n+1; i++)
        for (int j = 1; j <= n+1; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1'000'000'007;
    cout << dp[n+1][n+1] << " " << n*n;

}

int main()
{
    INPUT();
    solution();
}