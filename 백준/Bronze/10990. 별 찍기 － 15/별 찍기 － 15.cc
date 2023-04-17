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
    for(int j = 0; j < n-1; j++) cout << " ";
    cout << "*\n";
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n-1-i; j++) cout << " ";
        cout << "*";
        for(int j = 0; j < 2*i-1; j++) cout << " ";
        cout << "*\n";
    }
}

int main()
{
    INPUT();
    SOLVE();
}