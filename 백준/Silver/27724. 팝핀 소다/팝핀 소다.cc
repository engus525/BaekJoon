#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n, m, k;

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
}

void solution()
{
    ll pair_num = 0;
    if (k % 2) pair_num = (k - 1) / 2;
    else pair_num = k / 2;

    ll ans = (pair_num == 0) ? m : int(log2(pair_num)) + 1 + m;

    cout << min(ans, ll(log2(n)));
}

int main()
{
    INPUT();
    solution();
}