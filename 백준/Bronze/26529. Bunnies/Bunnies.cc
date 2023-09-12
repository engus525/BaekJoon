#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int dp[46];

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= 45; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    while (n--)
    {
        int x; cin >> x;
        cout << dp[x] << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}