#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, x, k;

void INPUT()
{
    IAMFAST
    cin >> n >> x >> k;
}

void solution()
{
    int ans = x;
    while (k--)
    {
        int a, b; cin >> a >> b;
        if (a != ans && b != ans) continue;

        if (a == ans) ans = b;
        else ans = a;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}