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

int c, n;
int dp[21][2001];
vector<pii> v;

void INPUT()
{
    IAMFAST
    cin >> c >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
}

void solution()
{
    sort(v.begin(), v.end(),
         [](pii &a, pii &b)
         {
             return a.first < b.first;
         });

    int ans = 2e9;
    for (int row = 1; row <= v.size(); row++)
    {
        auto [cost, person] = v[row - 1];
        for (int i = 1; i <= 2000; i++)
        {
            dp[row][i] = (dp[row-1][i]) ? dp[row-1][i] : 2e9;
            if (i % person == 0) dp[row][i] = min(dp[row][i], cost * (i / person));
            if (person <= i)
                dp[row][i] = min(dp[row][i], dp[row][i - person] + cost);
            if (i >= c) ans = min(ans, dp[row][i]);
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}