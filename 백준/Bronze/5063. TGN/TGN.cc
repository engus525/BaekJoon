#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    while(n--)
    {
        int a,b,c; cin>>a>>b>>c;
        if(a<b-c) cout << "advertise\n";
        else if(a>b-c) cout << "do not advertise\n";
        else cout << "does not matter\n";
    }
}

int main()
{
    INPUT();
    SOLVE();
}