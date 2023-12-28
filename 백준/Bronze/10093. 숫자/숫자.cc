#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    if (a > b) swap(a, b);
    if (a == b)
    {
        cout << 0;
        return;
    }
    cout << b - a - 1 << '\n';
    for (ll i = a + 1; i < b; i++) cout << i << " ";
}

int main()
{
    INPUT();
    solution();
}