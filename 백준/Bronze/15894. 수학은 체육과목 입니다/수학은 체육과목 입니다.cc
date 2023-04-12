#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

long long n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    cout << 4*n;
}

int main()
{
    INPUT();
    SOLVE();
}