#include <bits/stdc++.h>

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
    for (auto &s: str)
        cout << char(((int(s) - 3 + 'A') % 26) + 'A');
}


int main()
{
    INPUT();
    solution();
}