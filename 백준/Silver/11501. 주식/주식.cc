#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int t,n;
typedef long long ll;
ll day[1000001];
ll ans = 0;


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
        for(int i = 1; i <= n; i++) cin >> day[i];

        ans = 0;
        ll maxV = -1;
        for(int i = n; i >= 1; i--)
        {
            maxV = max(maxV, day[i]);
            ans += maxV - day[i];
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}