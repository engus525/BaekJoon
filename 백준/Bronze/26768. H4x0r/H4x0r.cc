#include <iostream>
#include <math.h>
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
    string ans;
    for (auto s : str)
    {
        if (s == 'a') ans += "4";
        else if (s == 'e') ans += "3";
        else if (s == 'i') ans += "1";
        else if (s == 'o') ans += "0";
        else if (s == 's') ans += "5";
        else ans += s;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}