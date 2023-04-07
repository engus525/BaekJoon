#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str;

void INPUT()
{
    IAMFAST
    cin >> str;
}

void SOLVE()
{
    string ans = "";
    for(auto i : str)
        if('A' <= i && i <= 'Z') ans += i;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}