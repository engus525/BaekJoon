#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<ll> v;
bool visited[11];

void INPUT()
{
    IAMFAST
}

void setComb(int val, int depth)
{
    if (depth == 10) return;
    if (val) v.emplace_back(val);

    for (int i = 0; i < 10; i++)
    {
        if (!i && ! val) continue;
        if (visited[i]) continue;

        val = val * 10 + i;
        visited[i] = true;
        setComb(val, depth + 1);
        visited[i] = false;
        val /= 10;
    }
}

void solution()
{
    setComb(0,0);
    sort(v.begin(), v.end());

    while (cin >> n)
    {
        if (!n) break;
        cout << v[n - 1] << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}