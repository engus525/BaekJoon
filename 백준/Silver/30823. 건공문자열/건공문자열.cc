#include <iostream>
#include <map>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b;
string str;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> str;
}

void solution()
{
    for (int i = b - 1; i < str.length(); i++) cout << str[i];
    for (int i = 0; i < b - 1; i++)
    {
        if ((a - b + 1) % 2) cout << str[b - 2 - i];
        else cout << str[i];
    }
}

int main()
{
    INPUT();
    solution();
}