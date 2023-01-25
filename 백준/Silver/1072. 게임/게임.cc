#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll x,y;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x >> y;
}


void SOLVE()
{

    ll z = y*100 / x;
    int left = 0,right = 1e9;
    int ans = -1;

    while(left <= right)
    {
        int mid = (left+right)/2;

        ll winRate = (y + mid)*100 / (x + mid);

        if(winRate > z) ans = mid,right = mid - 1;
        else left = mid + 1;
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}