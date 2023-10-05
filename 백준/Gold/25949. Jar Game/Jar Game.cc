#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c;
int dp[31][101][101][101];

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c;
}



int DP(int round, int x, int y, int z)
{
    if (dp[round][x][y][z]) return dp[round][x][y][z];

    int A, B, C;
    A = min(round, x);
    B = min(round, y);
    C = min(round, z);

    if (A + B + C == 0) return dp[round][x][y][z] = 0;

    int nRound = round + 1;
    if (round % 2)
    {
        if (x) dp[round][x][y][z] = max(dp[round][x][y][z],
                                     DP(nRound, x - A, y, z) + A);
        if (y) dp[round][x][y][z] = max(dp[round][x][y][z],
                                     DP(nRound, x, y - B, z) + B);
        if (z) dp[round][x][y][z] = max(dp[round][x][y][z],
                                     DP(nRound, x, y, z - C) + C);
    }
    else
    {
        dp[round][x][y][z] = 2e9;
        if (x) dp[round][x][y][z] = min(dp[round][x][y][z],
                                     DP(nRound, x - A, y, z));
        if (y) dp[round][x][y][z] = min(dp[round][x][y][z],
                                     DP(nRound, x, y - B, z));
        if (z) dp[round][x][y][z] = min(dp[round][x][y][z],
                                     DP(nRound, x, y, z - C));
    }
    return dp[round][x][y][z];
}

void solution()
{
    int F = DP(1, a, b, c);
    int S = a + b + c - F;

    if (F > S) cout << "F";
    else if (F < S) cout << "S";
    else cout << "D";
}

int main()
{
    INPUT();
    solution();
}