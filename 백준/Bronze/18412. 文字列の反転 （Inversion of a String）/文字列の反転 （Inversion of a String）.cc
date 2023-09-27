#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c;
string str;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c >> str;
}


void solution()
{
    for (int i = 0; i < str.length(); i++)
    {
        if (b <= i + 1 && i + 1 <= c) cout << str[b + c - i - 2];
        else cout << str[i];
    }
}

int main()
{
    INPUT();
    solution();
}