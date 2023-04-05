#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
}

void SOLVE()
{
    cout << (m-1)+(m*(n-1));
}

int main()
{
    INPUT();
    SOLVE();
}