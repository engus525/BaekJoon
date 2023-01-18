#include <iostream>
#include <string>
using namespace std;

string str;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


void SOLVE()
{
    while(getline(cin,str))
    {
        if(str == "#") break;

        int aeiou = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'a' || str[i] == 'e' ||
                str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' ||
                str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
                aeiou++;
        }
        cout << aeiou << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}