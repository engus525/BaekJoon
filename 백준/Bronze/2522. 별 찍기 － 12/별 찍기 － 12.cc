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
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1-i; j++) cout << " ";
        for(int j = 0; j <= i; j++) cout << "*";
        cout << '\n';
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++) cout << " ";
        for(int j = 0; j < n-i; j++) cout << "*";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}