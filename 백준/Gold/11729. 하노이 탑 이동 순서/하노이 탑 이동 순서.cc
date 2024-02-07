#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int dp[21];

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] * 2 + 1;
    cout << dp[n] << '\n';

    int forward = 1, backward = 1;
    for (int i = 0; i < dp[n]; i++)
    {
        int level = n;
        int idx = i;

        while (idx % 2)
        {
            idx /= 2;
            level--;
        }

        if (level % 2)
        {
            if (idx % 6 == 0) cout << 1 << " " << 3;
            else if ((idx - 2) % 6 == 0) cout << 3 << " " << 2;
            else if ((idx - 4) % 6 == 0) cout << 2 << " " << 1;
            cout << '\n';
        } else
        {
            if (idx % 6 == 0) cout << 1 << " " << 2;
            else if ((idx - 2) % 6 == 0) cout << 2 << " " << 3;
            else if ((idx - 4) % 6 == 0) cout << 3 << " " << 1;
            cout << '\n';
        }

    }
}

int main()
{
    INPUT();
    solution();
}