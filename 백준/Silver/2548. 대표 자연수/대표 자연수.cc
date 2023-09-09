#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<ll> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ll num; cin >> num;
        v.emplace_back(num);
    }
}

void solution()
{
    sort(v.begin(), v.end());

    ll minGap = 2e15;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ll gap = 0;
        for (int j = 0; j < n; ++j)
            gap += abs(v[i] - v[j]);
        
        if (minGap >= gap)
        {
            if (minGap > gap) ans = v[i];
            minGap = gap;
        }
        else break;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}