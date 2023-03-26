#include <iostream>
#include <unordered_map>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
ll n,k;
ll A[200001];
ll ps[200001];
unordered_map<ll,ll> uM;
ll ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> A[i];
        ps[i] = ps[i-1] + A[i];
        if(ps[i] == k) ans++;
    }
}

void SOLVE()
{
    for(int i = 1; i <= n; i++)
        ans += uM[ps[i]-k],
        uM[ps[i]]++;

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}