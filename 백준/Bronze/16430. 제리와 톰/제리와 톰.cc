#include<iostream>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a,b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void SOLVE()
{
    cout << b-a << " " << b;
}

int main()
{
    INPUT();
    SOLVE();
}