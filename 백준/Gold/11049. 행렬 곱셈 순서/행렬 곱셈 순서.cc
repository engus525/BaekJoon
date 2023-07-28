#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n;
pll mat[501];
ll dp[501][501];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> mat[i].first >> mat[i].second;
}


void solution()
{
    for (int gap = 1; gap <= n; gap++)
    {
        for(int left = 1; left + gap <= n; left++)
        {
            int right = left + gap;
            dp[left][right] = 2e10;
            for(int cri = left; cri <= right; cri++)
            {
                dp[left][right] = min(dp[left][right],
                                      dp[left][cri] +
                                      dp[cri+1][right] +
                                      mat[left].first * mat[cri].second * mat[right].second);
            }
        }
    }
    cout << dp[1][n];
}

int main()
{
    INPUT();
    solution();
}