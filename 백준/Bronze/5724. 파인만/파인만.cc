#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
}

void solution()
{
    while (cin >> n)
    {
        if (!n) break;

        int ans = 0;
        for (int i = 1; i <= n; i++) ans += i * i;
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}