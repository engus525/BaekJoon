#include <iostream>
#include <string>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str;
int B;

void INPUT()
{
    IAMFAST
    cin >> str >> B;
}

void SOLVE()
{
    int ans = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if('0' <= str[i] && str[i] <= '9')
            ans += (str[i]-'0')*pow(B,str.length()-1-i);
        else ans += (str[i]-'A'+10)*pow(B,str.length()-1-i);
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}