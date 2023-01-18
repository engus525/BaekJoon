#include <iostream>
#include <algorithm>
using namespace std;

int n;
int food[100001];
int dp[100001][3];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> food[i];
}


void SOLVE()
{
    dp[1][0] = food[1];
    dp[1][1] = food[1];
    dp[1][2] = food[1];

    dp[2][0] = food[1]; // x -> o or x
    dp[2][1] = food[1] + food[2] / 2; // ㅁ -> x
    dp[2][2] = food[2]; // o -> ㅁ or x

    int ans = max(dp[2][1],dp[2][2]);
    for(int i = 3; i <= n; i++)
    {
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2])); // x
        dp[i][1] = dp[i-1][2] + food[i] / 2; // ㅁ
        dp[i][2] = dp[i-1][0] + food[i]; // o

        ans = max(dp[i][0],max(dp[i][1],dp[i][2]));
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}