#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
string str;
bool no[100001];

void INPUT()
{
    IAMFAST
    cin >> n;
}

int isPelin(bool flag)
{
    if(str.length() == 1) return 0;
    else if(str.length() == 2)
    {
        if(str[0] == str[1]) return 0;
        else return 1;
    }

    int left = (no[0]) ? 1 : 0;
    int right = (no[str.length()-1]) ? str.length()-2 : str.length()-1;

    while(left <= right)
    {
        if(str[left] != str[right])
        {
            if(!flag)
            {
                no[left] = true;
                int l = isPelin(true);
                no[left] = false;

                no[right] = true;
                int r = isPelin(true);
                no[right] = false;

                if(l == 0 || r == 0) return 1;
                else return 2;
            }
            else return 2;
        }
        left = (no[left+1]) ? left+2 : left+1;
        right = (no[right-1]) ? right-2 : right-1;
    }
    return 0;
}

void SOLVE()
{
    while(n--)
    {
        cin >> str;
        memset(no,false,sizeof no);

        cout << isPelin(false) << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}