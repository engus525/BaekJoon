#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<pii> v;
vector<pii> comb;
int ans = 2e9;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pii taste;
        cin >> taste.first >> taste.second;
        v.emplace_back(taste);
    }
}

void setAns()
{
    int S = 1, B = 0;
    for (auto &c: comb)
    {
        S *= c.first;
        B += c.second;
    }
    ans = min(ans, abs(S - B));
}

void setComb(int depth, int start)
{
    if (depth > n) return;
    else if (depth) setAns();

    for (int i = start; i < n; i++)
    {
        comb.emplace_back(v[i]);
        setComb(depth + 1, i + 1);
        comb.pop_back();
    }
}

void solution()
{
    setComb(0, 0);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}