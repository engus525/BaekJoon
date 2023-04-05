#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void SOLVE()
{
    while(t--)
    {
        string str; cin >> str;
        cout << (str[0]-'0')+(str[2]-'0') << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}