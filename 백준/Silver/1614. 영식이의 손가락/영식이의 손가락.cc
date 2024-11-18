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

ll n, k;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
}


void solution()
{
    ll ans = 5;
    if (k)
    {
        if (2 <= n && n <= 4) ans += (k - 1) * 4;
        else if (n == 5) ans += (2 * k - 1) * 4;
        if (n == 1) ans += 8 * (k - 1);
    } else ans = n - 1;

    if (k && (n == 1 || n == 5)) ans += 3;
    else if (k)
    {
        // k가 짝수 : 왼 -> 오
        if (!(k % 2)) ans += n - 2;
        // k가 홀수 : 오 -> 왼
        else ans += 4 - n;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}