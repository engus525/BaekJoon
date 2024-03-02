#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int p, n;
priority_queue<int, vector<int>, greater<>> pq;

void INPUT()
{
    IAMFAST
    cin >> p >> n;
    for (int i = 0; i < n; i++)
    {
        int v; cin >> v;
        pq.emplace(v);
    }
}

void solution()
{
    int ans = 0;
    while (!pq.empty() && p < 200)
    {
        p += pq.top();
        pq.pop();
        ans++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}