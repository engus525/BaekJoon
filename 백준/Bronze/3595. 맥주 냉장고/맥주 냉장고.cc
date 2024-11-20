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

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    ll minV = 2e18;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (i * j > n) break;
            for (ll k = 1; k <= n; k++)
            {
                if (i * j * k > n) break;
                if (i * j * k != n) continue;

                ll calc = i * j + j * k + k * i;
                if (minV > calc)
                {
                    minV = calc;
                    a = i, b = j, c = k;
                }
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