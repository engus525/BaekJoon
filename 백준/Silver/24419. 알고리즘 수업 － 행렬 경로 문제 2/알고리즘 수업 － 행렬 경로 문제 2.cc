#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int graph[1002][1002];
int dp[1002][1002];
#define MOD 1'000'000'007

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> graph[i][j];
}


void solution()
{
    for (int i = 1; i <= n+1; i++)
        for (int j = 1; j <= n+1; j++)
        {
            if(i == 1 || j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    cout << dp[n+1][n+1] << " " << n*n;

}

int main()
{
    INPUT();
    solution();
}