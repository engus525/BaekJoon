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
    if(n) cout << "Leading the Way to the Future";
    else cout << "YONSEI";
}

int main()
{
    INPUT();
    SOLVE();
}