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
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << ((a % b) ? (a / b + 1) : (a / b)) << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}