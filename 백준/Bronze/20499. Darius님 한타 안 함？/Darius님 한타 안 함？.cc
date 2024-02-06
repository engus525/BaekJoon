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
    vector<int> v;

    string token;
    for (auto s : str)
    {
        if (s == '/')
        {
            v.emplace_back(stoi(token));
            token = "";
        }
        else token += s;
    }
    v.emplace_back(stoi(token));

    if (v[0] + v[2] < v[1] || v[1] == 0) cout << "hasu";
    else cout << "gosu";
}

int main()
{
    INPUT();
    solution();
}