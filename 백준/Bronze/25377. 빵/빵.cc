#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t, a, b;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    int ans = 2e9;
    while (t--)
    {
        cin >> a >> b;
        if (a <= b) ans = min(ans, b);
    }
    (ans == 2e9) ? (cout << -1) : (cout << ans);
}

int main()
{
    INPUT();
    solution();
}