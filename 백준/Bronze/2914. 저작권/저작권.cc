#include <iostream>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

double A,I;

void INPUT()
{
    IAMFAST
    cin >> A >> I;
}

void SOLVE()
{
    int ans = 0;
    for(double i = A*I; ceil(i/A) == I; i--) ans = i;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}