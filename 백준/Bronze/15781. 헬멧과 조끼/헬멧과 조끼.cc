#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int maxN, maxM;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v; cin >> v;
        maxN = max(maxN, v);
    }
    for (int i = 0; i < m; i++)
    {
        int v; cin >> v;
        maxM = max(maxM, v);
    }
}

void solution()
{
    cout << maxN + maxM;
}

int main()
{
    INPUT();
    solution();
}