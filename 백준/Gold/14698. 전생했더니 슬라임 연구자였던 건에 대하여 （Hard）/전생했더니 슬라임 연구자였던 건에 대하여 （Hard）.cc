#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define MOD 1'000'000'007
typedef long long ll;
int t;
ll n,c;

void INPUT()
{
    IAMFAST
    cin >> t;
}


void SOLVE()
{
    while(t--)
    {
        cin >> n;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        while(n--) cin >> c, pq.push(c);

        ll ans = 1;
        while(pq.size() != 1)
        {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ans *= ((a%MOD)*(b%MOD))%MOD;
            ans %= MOD;
            pq.push(a*b);
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}