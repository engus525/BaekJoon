#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

string str;
int dp[5001];
#define MOD 1'000'000

void INPUT()
{
    IAMFAST
    cin >> str;
}


void SOLVE()
{
    bool err = false;
    if (str[0] == '0') err = true;

    dp[0] = 1;
    if(str.length() >= 2)
    {
        if (str[0] >= '3' && str[1] == '0') err = true;
        else if (str[0] == '2')
        {
            if ('1' <= str[1] && str[1] <= '6') dp[1] = 2;
            else dp[1] = 1;
        }
        else if (str[0] == '1' && '1' <= str[1] && str[1] <= '9') dp[1] = 2;
        else dp[1] = 1;
    }

//    cout << dp[1] << '\n';
    for (int i = 2; i < str.length(); i++)
    {
        if (str[i] == '0')
        {
            if (str[i - 1] != '1' && str[i - 1] != '2')
            {
                err = true;
                break;
            }
            else dp[i] = dp[i - 2];
        }
        else if (((str[i - 1] == '1' || str[i - 1] == '2') && str[i] <= '6') ||
                   (str[i - 1] == '1' && str[i] >= '7'))
            dp[i] = dp[i - 1] + dp[i - 2];
        else dp[i] = dp[i - 1];

        dp[i] %= MOD;
//        cout << dp[i] << '\n';
    }

    if (err) cout << 0;
    else cout << dp[str.length() - 1];
}

int main()
{
    INPUT();
    SOLVE();
}