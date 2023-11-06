#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
priority_queue<ll> pq;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll tip;
        cin >> tip;
        pq.emplace(tip);
    }
}

void solution()
{
    ll ans = 0;

    ll fuck = 0;
    while (!pq.empty())
    {
        ll tip = pq.top();
        pq.pop();

        ans += max(ll(0), tip - fuck);
        fuck++;
    }
    cout << ans;
}


int main()
{
    INPUT();
    solution();
}