#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string a,b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void SOLVE()
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string ans = to_string(stoi(a)+stoi(b));
    reverse(ans.begin(),ans.end());
    ans = to_string(stoi(ans));
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}