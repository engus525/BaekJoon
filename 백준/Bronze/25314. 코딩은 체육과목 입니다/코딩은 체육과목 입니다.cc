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
    for(int i = 0; i < n/4; i++) cout << "long ";
    cout << "int";
}

int main()
{
    INPUT();
    SOLVE();
}