#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a,b,c;

void INPUT()
{
    IAMFAST
    cin>>a>>b>>c;
}


void SOLVE()
{
    if(a==b&&b==c&&a==60) cout << "Equilateral";
    else if(a+b+c==180&&(a==b||b==c||c==a)) cout << "Isosceles";
    else if(a+b+c==180&&(a!=b&&b!=c&&c!=a)) cout << "Scalene";
    else if(a+b+c!=180) cout << "Error";
}

int main()
{
    INPUT();
    SOLVE();
}