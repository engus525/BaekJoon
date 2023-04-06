#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int k,n,m;

void INPUT()
{
    IAMFAST
    cin >> k >> n >> m;
}

void SOLVE()
{
    int ans = (m < k * n) ? k * n - m : 0;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}