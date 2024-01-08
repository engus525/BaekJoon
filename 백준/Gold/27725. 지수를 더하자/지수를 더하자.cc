#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n, k;
vector<ll> prime;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll p;
        cin >> p;
        prime.emplace_back(p);
    }
    cin >> k;
}

void solution()
{
    ll ans = 0;
    for (auto p : prime)
    {
        ll temp = p;
        while (p <= k)
        {
            //cout << p << '\n';
            ans += k / p;
            p *= temp;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}