#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
ll n;
ll server[1001][1001];
ll Max = -1;
ll total;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> server[i][j],
            Max = max(Max,server[i][j]),
            total += server[i][j];
}


void SOLVE()
{

    ll left = 0,right = Max;

    ll ans;
    while(left <= right)
    {
        ll mid = (left + right) / 2;

        ll cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cnt += min(server[i][j],mid);

        if(2*cnt >= total) ans = mid , right = mid - 1;
        else left = mid + 1;
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}