#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    int ans = 0;
    while(n--)
    {
        int a,b; cin>>a>>b;

        ans += b%a;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}