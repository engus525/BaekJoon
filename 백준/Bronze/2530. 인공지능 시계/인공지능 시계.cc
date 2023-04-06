#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a,b,c,d;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c >> d;
}

void SOLVE()
{
    int mod = d % 60;
    c += mod;
    b += c/60; c %= 60;
    a += b/60; b %= 60;
    a %= 24;
    d /= 60;

    mod = d % 60;
    b += mod;
    a += b/60; b %= 60;
    a %= 24;
    d /= 60;

    a += d; a %= 24;

    cout << a << " " << b << " " << c;
}

int main()
{
    INPUT();
    SOLVE();
}