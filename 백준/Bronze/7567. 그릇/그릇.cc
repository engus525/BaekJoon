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
    int ans = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(i == 0) ans += 10;
        else if(str[i-1] == '(')
        {
            if(str[i] == '(') ans += 5;
            else ans += 10;
        }
        else if(str[i-1] == ')')
        {
            if(str[i] == ')') ans += 5;
            else ans += 10;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}