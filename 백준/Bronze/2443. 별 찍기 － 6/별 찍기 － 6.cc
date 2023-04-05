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
    for(int l = 0; l <= n; l++)
    {
        for(int i = 0; i < l; i++) cout << " ";
        for(int i = 0; i < 2*n-1-2*l; i++) cout << "*";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}