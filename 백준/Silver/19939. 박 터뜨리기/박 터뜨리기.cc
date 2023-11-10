#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
}

void solution()
{
    int ps = k * (k + 1) / 2;
    if (ps > n) cout << -1;
    else
    {
        if ((n - ps) % k == 0) cout << k - 1;
        else cout << k;
    }
}


int main()
{
    INPUT();
    solution();
}