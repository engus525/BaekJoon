#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,a,b;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void SOLVE()
{
    int A = 100, B = 100;
    while(n--)
    {
        cin >> a >> b;
        if(a < b) A -= b;
        else if (a > b) B -= a;
    }
    cout << A << "\n" << B;
}

int main()
{
    INPUT();
    SOLVE();
}