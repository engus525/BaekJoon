#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    cin.ignore();
    for(int i = 1; i <= n; i++)
    {
        string str; getline(cin,str);
        cout << i << ". " << str << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}