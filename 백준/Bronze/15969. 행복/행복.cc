#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    int maxV = 0, minV = 9999;
    for (int i = 0; i < n; i++)
    {
        int v; cin >> v;
        maxV = max(maxV, v);
        minV = min(minV, v);
    }
    cout << maxV - minV;
}

int main()
{
    INPUT();
    solution();
}