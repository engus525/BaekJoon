#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n;
ll a, b, c;
vector<ll> v;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    for (ll i = 1; i <= sqrt(n); i++)
        if (!(n % i)) v.emplace_back(i), v.emplace_back(n / i);

    ll minV = 2e18;
    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = 0; j < v.size(); j++)
        {
            ll k = n / v[i] / v[j];
            if (v[i] * v[j] * k != n) continue;

            ll calc = v[i] * v[j] + v[j] * k + k * v[i];
            if (minV > calc)
            {
                minV = calc;
                a = v[i], b = v[j], c = k;
            }
        }
    }
    cout << a << " " << b << " " << c;
}

int main()
{
    INPUT();
    solution();
}