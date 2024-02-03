#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int arr[2001];
int dp[2001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void solution()
{
    int ans = 1;

    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] <= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    cout << n - ans;
}

int main()
{
    INPUT();
    solution();
}