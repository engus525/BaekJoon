#include <iostream>
#include <string>
#include <cmath>

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
    for(int i = str.length()-1; i >= 0; i--)
    {
        if('A' <= str[i] && str[i] <= 'F')
            ans += (str[i]-'A'+10)*pow(16,str.length()-1-i);
        else ans += (str[i]-'0')*pow(16,str.length()-1-i);
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}