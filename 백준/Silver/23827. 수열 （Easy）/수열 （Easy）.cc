#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
ll num[500001];
#define MOD 1'000'000'007

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
}

void solution()
{
    ll ans = num[0] * num[1];
    ll sumV = num[0] + num[1];
    for (int i = 2; i < n; i++) ans += sumV * num[i], ans %= MOD, sumV += num[i];
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}