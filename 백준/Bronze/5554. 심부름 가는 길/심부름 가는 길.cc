#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a,b,c,d,sum=0;

void INPUT()
{
    IAMFAST
    cin>>a>>b>>c>>d;
}


void SOLVE()
{
    cout << (a+b+c+d)/60 << '\n' << (a+b+c+d)%60;
}

int main()
{
    INPUT();
    SOLVE();
}