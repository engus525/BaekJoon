#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int list[200001];
int dp[200001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> list[i];
}

void solution()
{
    for (int i = n; i >= 1; i--)
    {
        if (i + list[i] + 1 > n) dp[i] = 1;
        else dp[i] = dp[i + list[i] + 1] + 1;
    }

    for (int i = 1; i <= n; ++i) cout << dp[i] << " ";
}

int main()
{
    INPUT();
    solution();
}