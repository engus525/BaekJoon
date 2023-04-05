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
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)cout << "*";
        cout << "\n";
    }
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)cout << "*";
        cout << "\n";
    }
}

int main()
{
    INPUT();
    SOLVE();
}