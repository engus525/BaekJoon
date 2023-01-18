#include <iostream>
#include <algorithm>
using namespace std;



void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

}

void SOLVE()
{
    int ans = 0, now = 0;
    for(int i = 0; i < 4; i++)
    {
        int off, on; cin >> off >> on;
        now -= off; now += on;
        ans = max(ans, now);
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
