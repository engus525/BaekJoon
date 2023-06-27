#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
typedef long long ll;
priority_queue<pair<int,ll>, vector<pair<int,ll>>, greater<>> pq;
priority_queue<ll, vector<ll>, greater<>> P;
ll ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll p,d; cin >> p >> d;
        pq.emplace(d,p);
    }
}


void SOLVE()
{
    while(!pq.empty())
    {
        auto [d,p] = pq.top();
        P.emplace(p);
        ans += p;
        pq.pop();

        if (P.size() > d)
        {
            ans -= P.top();
            P.pop();
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}