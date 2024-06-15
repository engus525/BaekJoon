#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, t;
int price[11];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> price[i];
    cin >> t;
}

void solution()
{
    int ans = 0;
    while (t--)
    {
        int m; cin >> m;
        ans += price[m - 1];
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}