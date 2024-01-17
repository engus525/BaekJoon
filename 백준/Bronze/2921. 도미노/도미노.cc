#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    int ans = 3;
    for (int i = 2; i <= n; i++)
    {
        ans += (2 * i) + (2 * i - 1);
        for (int j = i; j < 2 * i - 1; j++)
            ans += j;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}