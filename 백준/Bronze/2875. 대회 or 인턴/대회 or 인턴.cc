#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m,k;

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k;
}

void SOLVE()
{
    cout << min(min(n/2,m),(n+m-k)/3);
}

int main()
{
    INPUT();
    SOLVE();
}