#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
int ps[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 1; i <= n; i++)  cin >> ps[i], ps[i] += ps[i - 1];
}

void solution()
{
    int ans = -2e9;
    for (int i = k; i <= n; i++)
        ans = max(ans, ps[i] - ps[i - k]);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}