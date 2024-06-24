#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
string str;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        cin >> str;
        if (str[str.length() / 2 - 1] == str[str.length() / 2]) cout << "Do-it\n";
        else cout << "Do-it-Not\n";
    }
}

int main()
{
    INPUT();
    solution();
}