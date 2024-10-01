#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

ll n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    ll ans = sqrt(n);
    if (ans * ans < n) ans++;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}