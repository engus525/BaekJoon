#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a,b;

void INPUT()
{
    IAMFAST
}

void SOLVE()
{
    while(cin >> a >> b)
    {
        if(a+b == 0) break;
        cout << a+b << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}