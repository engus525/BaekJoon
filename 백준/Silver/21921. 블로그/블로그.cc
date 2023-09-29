#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, x;
int ps[250001];

void INPUT()
{
    IAMFAST
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> ps[i], ps[i] += ps[i - 1];
}


void solution()
{
    pii ans = {0, 0};
    for (int i = x; i <= n; i++)
    {
        int total = ps[i] - ps[i - x];
        if (ans.first < total) ans = {total, 1};
        else if (ans.first == total) ans.second++;
    }
    if (ans.first == 0) cout << "SAD";
    else cout << ans.first << '\n' << ans.second;
}

int main()
{
    INPUT();
    solution();
}