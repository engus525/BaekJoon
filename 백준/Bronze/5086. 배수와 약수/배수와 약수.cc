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
        if(!a) break;

        bool factor = (!(b%a)) ? true : false;
        bool multiple = (!(a%b)) ? true : false;

        if(factor) cout << "factor\n";
        else if(multiple) cout << "multiple\n";
        else cout << "neither\n";
    }
}

int main()
{
    INPUT();
    SOLVE();
}