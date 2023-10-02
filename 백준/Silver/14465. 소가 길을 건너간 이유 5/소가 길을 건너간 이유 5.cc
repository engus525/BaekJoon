#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k, b;
int ps[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> k >> b;
    for (int i = 1; i <= n; i++) ps[i] = 1;
    for (int i = 0; i < b; i++)
    {
        int num; cin >> num;
        ps[num] = 0;
    }
}


void solution()
{
    for (int i = 1; i <= n; i++) ps[i] += ps[i - 1];

    int ans = 2e9;
    for (int i = k; i <= n; i++)
    {
        int cnt = ps[i] - ps[i - k];
        ans = min(ans, k - cnt);
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}