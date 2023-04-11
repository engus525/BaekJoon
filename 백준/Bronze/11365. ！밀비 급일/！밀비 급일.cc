#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str;

void INPUT()
{
    IAMFAST
}

void SOLVE()
{
    while(getline(cin,str))
    {
        if(str == "END") break;
        for(int i = str.length()-1; i >= 0; i--)
            cout << str[i];
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}