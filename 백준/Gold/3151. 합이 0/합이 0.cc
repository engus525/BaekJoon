#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int list[10001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> list[i];
}


void solution()
{
    sort(list, list + n);

    ll ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int s = list[i] + list[j];
            ll lb = lower_bound(list + (j + 1), list + n, s * -1) - list;
            ll ub = upper_bound(list + (j + 1), list + n, s * -1) - list;
            ans += ub - lb;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}