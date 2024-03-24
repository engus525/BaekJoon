#include <bits/stdc++.h>
using namespace std;
                                                                                                                                                                                     
int n, ans = 0;
int tree[501][501], dp[501][501];


int main() {

    // 트리 입력
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> tree[i][j];

    dp[1][1] = tree[1][1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tree[i][j];
            ans = (ans < dp[i][j]) ? dp[i][j] : ans;
        }

    cout << ans;
}
