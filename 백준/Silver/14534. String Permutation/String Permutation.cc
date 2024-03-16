#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
string str;
bool visited[5];
vector<char> comb;
vector<string> ans;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void setComb(int depth)
{
    if (depth == str.length())
    {
        for (auto c : comb) cout << c;
        cout << '\n';
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        comb.emplace_back(str[i]);
        setComb(depth + 1);
        visited[i] = false;
        comb.pop_back();
    }
}

void solution()
{
    for (int i = 0; i < t; i++)
    {
        memset(visited, false, sizeof visited);
        ans.clear();
        comb.clear();

        cin >> str;
        cout << "Case # " << i + 1 << ":\n";
        setComb(0);
    }
}

int main()
{
    INPUT();
    solution();
}