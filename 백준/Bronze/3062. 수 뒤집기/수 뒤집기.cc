#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string str,rstr;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
}


void SOLVE()
{
    while(n--)
    {
        cin >> str;
        rstr = str;
        reverse(str.begin(),str.end());
        int num = stoi(str) + stoi(rstr);

        string s = to_string(num);
        string rs = s;
        reverse(s.begin(),s.end());

        if(s == rs) cout << "YES\n";
        else cout << "NO\n";

    }
}

int main()
{
    INPUT();
    SOLVE();
}