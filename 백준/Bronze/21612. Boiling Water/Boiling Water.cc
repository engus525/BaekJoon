#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;


void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    int v = t * 5 - 400;
    cout << v << '\n';

    if (v < 100) cout << 1;
    else if (v == 100) cout << 0;
    else cout << -1;
}

int main()
{
    INPUT();
    solution();
}