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

int n, m;
int w[31];
int ball[8];
#define MAX_COL (40000 + 500 + 1)
bool dp[31][MAX_COL];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> ball[i];
}

void solution()
{
    for (int row = 1; row <= n; row++)
    {
        int weight = w[row - 1];
        for (int col = 1; col < MAX_COL; col++)
        {
            dp[row][col] = dp[row - 1][col];
            if (weight == col) dp[row][col] = true;
            if (col - weight >= 0 && dp[row - 1][col - weight])
                dp[row][col] = true;
            if (col + weight < MAX_COL && dp[row - 1][col + weight])
                dp[row][col] = true;
            for (int i = max(0, col - weight); i < weight; i++)
            {
                if (!dp[row - 1][i]) continue;
                if (weight - i == col) dp[row][col] = true;
            }

        }
    }

    for (int i = 0; i < m; i++)
    {
        if (dp[n][ball[i]]) cout << "Y ";
        else cout << "N ";
    }
}

int main()
{
    INPUT();
    solution();
}