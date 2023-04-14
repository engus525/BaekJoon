#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void SOLVE()
{
    while(t--)
    {
        int n; cin >> n;

        int ans = 0,num;
        while(n-- && cin >> num) ans += num;
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}