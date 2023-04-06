#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str[16];
int maxLen = 1;

void INPUT()
{
    IAMFAST
    for(int i = 0; i < 5; i ++)
        cin >> str[i],
        maxLen= max(maxLen,(int)str[i].length());
}

void SOLVE()
{
    for(int i = 0; i < maxLen; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if (str[j].length()-1 < i) continue;
            else cout << str[j][i];
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}