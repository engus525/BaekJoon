#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<char> v;
ll comb;
bool visited[10];
pll ans = {2e11, 0};

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char op; cin >> op;
        v.emplace_back(op);
    }
}

void setAns()
{
    ans = {min(ans.first, comb), max(ans.second, comb)};
}

void setComb(int depth)
{
    if (depth == n + 1)
    {
        setAns();
        return;
    }

    for(int i = 0; i <= 9; i++)
    {
        if (visited[i]) continue;
        if (depth && v[depth - 1] == '>' && comb % 10 <= i) continue;
        if (depth && v[depth - 1] == '<' && comb % 10 >= i) continue;

        visited[i] = true;
        comb = comb * 10 + i;
        setComb(depth + 1);
        visited[i] = false;
        comb /= 10;
    }
}

void solution()
{
    setComb(0);
    string minAns = (to_string(ans.first).length() == n) ?
            "0" + to_string(ans.first) : to_string(ans.first);
    string maxAns = (to_string(ans.second).length() == n) ?
            "0" + to_string(ans.second) : to_string(ans.second);
    cout << maxAns << " " << minAns;
}

int main()
{
    INPUT();
    solution();
}