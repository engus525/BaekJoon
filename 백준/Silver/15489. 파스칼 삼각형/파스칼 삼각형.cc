#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int r, c, w;
int dp[31][31];

void INPUT()
{
    IAMFAST
    cin >> r >> c >> w;
}

void solution()
{

    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == 1 || j == 1) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < w; i++)
        for (int j = 0; j <= i; j++)
            ans += dp[r + i][c + j];
    cout << ans;

}

int main()
{
    INPUT();
    solution();
}