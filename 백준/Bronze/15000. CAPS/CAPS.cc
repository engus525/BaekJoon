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
}


void solution()
{
    cin >> str;
    for (auto &s : str) cout << char(s - 'a' + 'A');
}

int main()
{
    INPUT();
    solution();
}