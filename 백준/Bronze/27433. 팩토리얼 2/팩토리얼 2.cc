#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
        ans *= i;
    cout << ans;
}