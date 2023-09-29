#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
int ps[1001];

void INPUT()
{
    IAMFAST
    cin >> t;
}


void solution()
{
    while (t--)
    {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> ps[i], ps[i] += ps[i - 1];

        int ans = -2e9;
        for (int gap = 1; gap <= n; gap++)
            for (int e = gap; e <= n; e++)
                ans = max(ans, ps[e] - ps[e - gap]);
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}