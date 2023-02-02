#include <iostream>
#include <string>
using namespace std;

string str, pw;
string key = "";

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str >> pw;
}


void SOLVE()
{
    for (int i = 0; i < str.size(); i++)
    {
        int keyInt = pw[i] - str[i];
        if (keyInt < 1) keyInt += 26;
        key += char(keyInt + 'A' - 1);
    }

    string ans;
    if(key.length() == 1) ans = key;

    for (int i = 1; i <= key.length(); i++)
    {
        if (str.length() % i == 0)
        {// 키의 길이가 평문 길이의 약수라면

            string tempKey = key.substr(0, i);
            int range = key.length() - tempKey.length();

            if(!range) ans = key;
            for (int j = i; j <= key.length() - tempKey.length(); j += tempKey.length())
            {
                if (tempKey != key.substr(j, i))
                {
                    ans = "";
                    break;
                }
                else if (ans == "") ans = tempKey;
            }
            if(ans != "") break;
        }
    }

    cout << ans;
}


int main()
{
    INPUT();
    SOLVE();
}