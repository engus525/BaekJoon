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

ll n, m;
ll ps[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll a, b; cin >> a >> b;
        if (a == 1) ps[i] = ps[i - 1] + b;
        else if (a == 2) ps[i] = ps[i - 1] - b;
        else ps[i] = ps[b];
        ps[i] %= n;

//        ll ans = (1 + ps[i] + n) % n;
//        cout << (ans ? ans : n) << '\n';
    }
}

void solution()
{
    ll ans = (1 + ps[m] + n) % n;
    cout << (ans ? ans : n);
}


int main()
{
    INPUT();
    solution();
}