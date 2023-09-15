#include <iostream>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
ll dp[31][31];

void INPUT()
{
    IAMFAST
}

void solution()
{

    for (int half = 0; half <= 30; half++)
    {
        for (int one = 0; one <= 30; one++)
        {
            if (one < half) continue;

            if (one == 0 || half == 0) dp[one][half] = 1;
            else dp[one][half] = dp[one - 1][half] + dp[one][half - 1];
        }
    }

    while (cin >> n)
    {
        if (n == 0) break;
        cout << dp[n][n] << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}