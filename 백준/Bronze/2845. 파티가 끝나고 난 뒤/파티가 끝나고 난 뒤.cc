#include <iostream>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int l,p;

void INPUT()
{
    IAMFAST
    cin >> l >> p;
}

void SOLVE()
{
    for(int i = 0; i < 5; i++)
    {
        int num; cin >> num;
        cout << num - l*p << " ";
    }
}

int main()
{
    INPUT();
    SOLVE();
}