#include <iostream>
#include <map>
#include <string>
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
}

void solution()
{
    while (getline(cin, str))
    {
        if (str == "#") break;

        int cnt = 0;
        for (auto s : str)
            if (::tolower(s) == str[0]) cnt++;
        cout << str[0] << " " << cnt - 1 << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}