#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a,b;

void INPUT()
{
    IAMFAST
}


void SOLVE()
{
    int now = 0; int ans = -1;
    for(int _=0; _<10; _++)
    {
        cin >> a >> b;
        now -= a;
        now += b;
        ans = (ans < now) ? now : ans;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}