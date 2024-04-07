#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n;
vector<ll> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        ll sum = 0;
        while (num--)
        {
            ll t; cin >> t;
            sum += t;
        }
        v.emplace_back(sum);
    }
}

void solution()
{
    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i< n; i++)
        ans += v[i] * (n - i);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}