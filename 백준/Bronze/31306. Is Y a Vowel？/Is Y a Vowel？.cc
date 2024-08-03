#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;

void INPUT()
{
    IAMFAST
    cin >> str;
}

void solution()
{
    int a = 0, b = 0;
    for (auto s: str)
    {
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') a++;
        else if (s == 'y') b++;
    }
    cout << a << " " << a + b;
}

int main()
{
    INPUT();
    solution();
}