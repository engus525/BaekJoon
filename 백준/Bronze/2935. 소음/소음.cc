#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string a,oper,b;

void INPUT()
{
    IAMFAST
    cin >> a >> oper >> b;
}

void SOLVE()
{
    if(oper == "*")
    {
        if(b.length() > 1) cout << a+b.substr(1,b.length()-1);
        else cout << a;
    }
    else if(oper == "+")
    {

        int startA=0,startB=0;
        if(a.length() > b.length())
        {
            startA = a.length() - b.length();
            for (int i = 0; i < a.length() - b.length(); i++)
                cout << a[i];
        }
        else if(a.length() < b.length())
        {
            startB = b.length() - a.length();
            for (int i = 0; i < b.length() - a.length(); i++)
                cout << b[i];
        }

        for(; startA < a.length(); startA++,startB++)
        {
            if(a[startA] == b[startB])
            {
                if(a[startA] == '1') cout << "2";
                else if(a[startA] == '0') cout << "0";
            }
            else cout << "1";
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}