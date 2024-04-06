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
    while (n--)
    {
        int v; cin >> v;
        if (v % 2) cout << v << " is odd\n";
        else cout << v << " is even\n";
    }
}

int main()
{
    INPUT();
    solution();
}