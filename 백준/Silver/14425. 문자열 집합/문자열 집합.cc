#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
vector<string> v;
set<string> S;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;
        S.emplace(str);
    }
    for (int i = 0; i < m; i++)
    {
        string str; cin >> str;
        v.emplace_back(str);
    }
}

void solution()
{
    int ans = 0;
    for (auto &str : v)
        if (S.find(str) != S.end())
            ans++;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}