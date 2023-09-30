#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
ll t[1000001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> t[i];
}


void solution()
{
    ll ans = 0;

    ll l = 1, r = 1e12;
    while (l <= r)
    {
        ll mid = (l + r) / 2;

        ll cnt = 0;
        for (int i = 0; i < n; i++) cnt += mid / t[i];

        if (cnt < m) l = mid + 1;
        else ans = mid, r = mid - 1;
    }

    cout << ans;
}

int main()
{
    INPUT();
    solution();
}