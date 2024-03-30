#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
string str;

void INPUT()
{
    IAMFAST
    cin >> n >> str;
}

void solution()
{
    string reg;
    for (auto s : str)
    {
        if (s == '*') reg += ".*";
        else reg += s;
    }

    regex e(reg);
    while (n--)
    {
        string file; cin >> file;
        regex_match(file, e) ? cout << "DA\n" : cout << "NE\n";
    }
}

int main()
{
    INPUT();
    solution();
}