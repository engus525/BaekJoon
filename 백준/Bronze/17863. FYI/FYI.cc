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
    (str.substr(0, 3) == "555") ? cout << "YES" : cout << "NO";
}

int main()
{
    INPUT();
    solution();
}