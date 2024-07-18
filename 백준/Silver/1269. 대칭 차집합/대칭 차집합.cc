#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
set<int> a, b;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        a.emplace(v);
    }
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        b.emplace(v);
    }
}

void solution()
{
    int ans = a.size() + b.size();
    for (auto v: a)
        if (b.find(v) != b.end()) ans--;
    for (auto v: b)
        if (a.find(v) != a.end()) ans--;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}