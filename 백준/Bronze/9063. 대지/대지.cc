#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    ll minX = 2e9, maxX = -1e9, minY = 2e9, maxY = -1e9;

    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    if (minX == maxX || minY == maxY) cout << 0;
    else cout << (maxX - minX) * (maxY - minY);
}


int main()
{
    INPUT();
    solution();
}