#include <iostream>
#include <string>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string n;

void INPUT()
{
    IAMFAST
}

void SOLVE()
{
    while(cin >> n)
    {
        if(n=="0") break;

        int ans = n.length() + 1;
        for(int i = 0; i < n.length(); i++)
        {
            if(n[i] == '1') ans += 2;
            else if(n[i] == '0') ans += 4;
            else ans += 3;
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}