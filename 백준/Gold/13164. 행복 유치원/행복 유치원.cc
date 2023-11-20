#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
int tall[300001];
priority_queue<int> pq;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> tall[i];
        if (i)
        {
            pq.emplace(tall[i] - tall[i - 1]);
            ans += tall[i] - tall[i - 1];
        }
    }
}


void solution()
{
    for (int i = 0; i < k - 1; i++) ans -= pq.top(), pq.pop();
    cout << ans;
}


int main()
{
    INPUT();
    solution();
}