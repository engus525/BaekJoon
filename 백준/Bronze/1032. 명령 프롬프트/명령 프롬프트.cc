#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
string str[51];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> str[i];
}

void SOLVE()
{
    string ans = "";
    for(int i = 0; i < str[0].length(); i++)
    {
        bool allSame = true;
        for(int j = 0; j < n; j++)
        {
            if(str[j][i] != str[0][i])
            {
                allSame = false;
                break;
            }
        }
        ans += (allSame) ? str[0][i] : '?';
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}