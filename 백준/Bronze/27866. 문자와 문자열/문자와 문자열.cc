#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str;
int n;

void INPUT()
{
    IAMFAST
    cin >> str >> n;
}

void SOLVE()
{
    cout << str[n-1];
}

int main()
{
    INPUT();
    SOLVE();
}