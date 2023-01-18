#include <iostream>
#include <queue>
using namespace std;

string str;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}

bool aeiou(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
void SOLVE()
{
    while(cin >> str)
    {
        if(str == "#")
            break;

        for(int i = 0; i < str.length(); i++)
        {
            if(aeiou(str[0])) break;
            str += str[0];
            str.erase(0, 1);
        }

        cout << str + "ay\n";
    }
}

int main()
{
    INPUT();
    SOLVE();
}
