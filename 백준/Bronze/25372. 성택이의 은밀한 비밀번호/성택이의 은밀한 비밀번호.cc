#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
string str;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    while(n--)
    {
        cin >> str;
        string ans = (6 <= str.length() && str.length() <= 9) ? "yes\n" : "no\n";
        cout << ans;
    }
}

int main()
{
    INPUT();
    SOLVE();
}