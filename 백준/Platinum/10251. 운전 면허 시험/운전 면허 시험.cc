#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
int n, m, l, g;
int dp[101][101][201][2];
pii cost[101][101];//{go right, go down}

void INPUT()
{
    IAMFAST
    cin >> t;
}

void caseInput()
{
    cin >> n >> m >> l >> g;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            cin >> cost[i][j].first;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> cost[i][j].second;
}

void init()
{
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int x = 0; x < 200; x++)
                for (int y = 0; y < 2; y++)
                    dp[i][j][x][y] = 2e9;

    dp[0][0][0][0] = dp[0][0][0][1] = 0;
}

void solution()
{
    while (t--)
    {
        caseInput();
        init();


        //dp
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int turn = 0; turn <= i + j; turn++)
                {
                    if (i + 1 < n)
                    {
                        //right -> down
                        dp[i + 1][j][turn + 1][1] = min(dp[i + 1][j][turn + 1][1],
                                                        dp[i][j][turn][0] + cost[i + 1][j].second);
                        //down -> down
                        dp[i + 1][j][turn][1] = min(dp[i + 1][j][turn][1],
                                                    dp[i][j][turn][1] + cost[i + 1][j].second);
                    }
                    if (j + 1 < m)
                    {
                        //right -> right
                        dp[i][j + 1][turn][0] = min(dp[i][j + 1][turn][0],
                                                    dp[i][j][turn][0] + cost[i][j + 1].first);
                        //down -> right
                        dp[i][j + 1][turn + 1][0] = min(dp[i][j + 1][turn + 1][0],
                                                        dp[i][j][turn][1] + cost[i][j + 1].first);
                    }
                }

        //get answer
        int minTurn = 200;
        for (int i = 1; i < 200; i++)
            if (dp[n - 1][m - 1][i][0] <= g || dp[n - 1][m - 1][i][1] <= g)
                minTurn = min(minTurn, i);

        (minTurn == 200) ? cout << -1 : cout << minTurn + l * (n + m - 2);
        cout << '\n';

    }
}

int main()
{
    INPUT();
    solution();
}