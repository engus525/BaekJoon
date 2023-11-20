#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string a, b;
int dp[4001][4001];
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j]) dp[i][j] = 1;
            else continue;

            if (!i || !j) continue;

            dp[i][j] += dp[i - 1][j - 1];
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}


int main()
{
    INPUT();
    solution();
}