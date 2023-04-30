#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a[3];

void INPUT()
{
    IAMFAST
    cin >> a[0] >> a[1] >> a[2];
}


void SOLVE()
{
    sort(a,a+3);
    cout << a[1];
}

int main()
{
    INPUT();
    SOLVE();
}