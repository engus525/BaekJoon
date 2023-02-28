#include<iostream>
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
        int a,b; cin >> a >> b;
        cout << a+b << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}