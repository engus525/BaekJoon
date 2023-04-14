#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t,n;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void SOLVE()
{
    while(t--)
    {
        cin >> n; int idx = 0;
        while(n)
        {
            if(n%2) cout << idx << " ";
            n /= 2;
            idx++;
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}