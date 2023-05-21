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
    int ps = 2;
    int value = 1;
    for(int i = 0; i < n; i++)
    {
        ps += value;
        value = 2*value;
    }
    cout << ps*ps;
}

int main()
{
    INPUT();
    SOLVE();
}