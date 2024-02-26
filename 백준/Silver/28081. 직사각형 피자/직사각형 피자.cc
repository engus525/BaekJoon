#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll w, h, k, n, m;
ll X[100001], Y[100001];
vector<ll> xPos, yPos;

void INPUT()
{
    IAMFAST
    cin >> w >> h >> k >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Y[i];
        if (i) yPos.emplace_back(Y[i] - Y[i - 1]);
        else yPos.emplace_back(Y[i]);
    }
    yPos.emplace_back(h - Y[n - 1]);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> X[i];
        if (i) xPos.emplace_back(X[i] - X[i - 1]);
        else xPos.emplace_back(X[i]);
    }
    xPos.emplace_back(w - X[m - 1]);

}

void solution()
{
    ll ans = 0;
    sort(yPos.begin(), yPos.end());
    for (auto x : xPos)
    {
        ll yLimit = k / x;
        ans += upper_bound(yPos.begin(), yPos.end(), yLimit) - yPos.begin();
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}