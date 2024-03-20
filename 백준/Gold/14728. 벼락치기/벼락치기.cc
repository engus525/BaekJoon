#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int dp[101][10001];
int n, t;
vector<pii> v;

void INPUT()
{
    IAMFAST
    cin >> n >> t;
    v.emplace_back(0, 0);
    for (int i = 0; i < n; i++)
    {
        int k, s;
        cin >> k >> s;
        v.emplace_back(k, s);
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= t; j++)
        {
            if (j - v[i].first < 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
        }
    cout << dp[n][t];
}

int main()
{
    INPUT();
    solution();
}