#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n, k;
ll dist[100001], ps[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        cin >> dist[i];
        if (dist[i] > k) ps[i] = 1;
        ps[i] += ps[i - 1];
    }
}


void solution()
{
    int ans = 1;

    int l = 0, r = 1;
    while (l <= r && r < n)
    {
        if (ps[r] - ps[l] <= 1) ans = max(ans, r - l + 1), r++;
        else l++;
    }
    cout << ans;
}


int main()
{
    INPUT();
    solution();
}