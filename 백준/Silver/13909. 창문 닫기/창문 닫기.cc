#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    ll ans = 0;
    for(int i = 1; i * i <= n; i++) ans++;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}