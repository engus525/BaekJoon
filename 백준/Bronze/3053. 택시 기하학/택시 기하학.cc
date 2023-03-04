#include <iostream>
#include <cmath>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

double r;

void INPUT()
{
    IAMFAST
    cin >> r;
}

void SOLVE()
{
    cout.precision(6); cout << fixed;
    cout << M_PI*r*r << '\n' << 2*r*r;
}

int main()
{
    INPUT();
    SOLVE();
}