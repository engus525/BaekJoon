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
    int a = n/2+1;
    int b = n/2+1;
    if(n%2) b++;
    cout << a*b;
}

int main()
{
    INPUT();
    SOLVE();
}