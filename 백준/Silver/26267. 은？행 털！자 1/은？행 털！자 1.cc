#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include <memory.h>
#include <map>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

ll n;
map<ll, ll> M;

void INPUT()
{
    IAMFAST
    cin >> n;
    while (n--)
    {
        ll x, t, c; cin >> x >> t >> c;
        M[x - t] += c;
    }
}



void solution()
{
    ll ans = 0;
    for (auto [k, v] : M) ans = max(ans, v);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}