#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

ll n, k;
ll ml[10001];
ll l, r;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> ml[i];
        r = max(r, ml[i]);
    }
}

void solution()
{
    ll ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (mid == 0) mid = 1;
        ll count = 0;
        for (int i = 0; i < n; i++)
        {
            count += ml[i] / mid;
        }

        if (count >= k)
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}