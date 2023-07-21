#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n;
int graph[4001][4001];
int dp[4001][4001];
#define MOD 1'000'000'007
int ans1, ans2;

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
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if(i == 1 || j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j]%MOD + dp[i][j-1]%MOD)%MOD;
        }

    int ans = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += dp[i][j], ans %= MOD;
    cout << ans << " ";

    cout << n*n;

}

int main()
{
    INPUT();
    solution();
}