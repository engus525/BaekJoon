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

string target, devil, angel;
int dp[2][101][21];//{악마,천사} {돌다리 index} {두루마리 index}

void INPUT()
{
    IAMFAST
    cin >> target >> devil >> angel;
}


void solution()
{
    //init
    for (int i = 0; i < devil.length(); i++)
    {
        if (devil[i] == target[0]) dp[0][i][0] = 1;
        if (angel[i] == target[0]) dp[1][i][0] = 1;
    }

    //dp
    for (int i = 0; i < devil.length(); i++)
    {
        for (int j = 1; j < target.length(); j++)
        {
            if (devil[i] == target[j])
            {
                int cnt = 0;
                for (int k = 0; k < i; k++)
                    cnt += dp[1][k][j - 1];
                dp[0][i][j] = cnt;
            }

            if (angel[i] == target[j])
            {
                int cnt = 0;
                for (int k = 0; k < i; k++)
                    cnt += dp[0][k][j - 1];
                dp[1][i][j] = cnt;
            }
        }
    }

    //output
    int ans = 0;
    for (int i = 0; i < devil.length(); i++)
        ans += dp[0][i][target.length() - 1] +
               dp[1][i][target.length() - 1];
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}