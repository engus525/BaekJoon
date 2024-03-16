#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
vector<string> v;
vector<string> comb;
set<string> ans;
bool visited[11];

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.emplace_back(str);
    }
}

void setComb(int depth)
{
    if (depth == k)
    {
        string str;
        for (auto c : comb)
            str += c;
        ans.emplace(str);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        comb.emplace_back(v[i]);
        setComb(depth + 1);
        visited[i] = false;
        comb.pop_back();
    }
}

void solution()
{
    setComb(0);
    cout << ans.size();
}

int main()
{
    INPUT();
    solution();
}