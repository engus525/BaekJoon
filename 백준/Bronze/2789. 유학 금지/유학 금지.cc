#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;
bool ban[30];

void INPUT()
{
    IAMFAST
    cin >> str;
}

void solution()
{
    string cambridge = "CAMBRIDGE";
    for (auto s : cambridge) ban[s - 'A'] = true;
    for (auto s : str)
    {
        if (ban[s - 'A']) continue;
        cout << s;
    }
}


int main()
{
    INPUT();
    solution();
}