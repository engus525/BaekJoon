#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int t;
string str;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    cin.ignore();
    while(t--)
    {
        double num; cin >> num;
        getline(cin,str);

        for(auto &s : str)
        {
            if(s == ' ') continue;
            else if (s == '@') num *= 3;
            else if (s == '%') num += 5;
            else if (s == '#') num -= 7;
        }
        cout << fixed; cout.precision(2);
        cout << num << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}