#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m;
typedef long long ll;
vector<ll> v;
ll sumV = 0, maxV = -1;
ll ans = 2e18;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll need;
        cin >> need;
        sumV += need;
        maxV = max(maxV, need);
        v.emplace_back(need);
    }
}

void SOLVE()
{

    ll left = 1, right = sumV;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if(maxV > mid)
        {
            left = mid + 1;
            continue;
        }

        int cnt = 0;
        ll now = 0;
        for (auto &i: v)
        {
            if (i > now) cnt++, now = mid - i;
            else now -= i;
        }

        if (cnt > m) left = mid + 1;
        else
        {
            ans = mid;
            right = mid - 1;
        }

    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}