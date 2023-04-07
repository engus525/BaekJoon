#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
    //버퍼에 '\n' 들어가는 것 방지
    cin.ignore();
}

void SOLVE()
{
    while(n--)
    {
        string str;
        getline(cin,str);

        for(int i = 0; i < str.length(); i++)
        {
            if(str[i+1] == ' ' || i+1 == str.length())
            {
                int idx = i;
                while(0 <= idx && str[idx] != ' ') cout << str[idx--];
                cout << " ";
            }
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}