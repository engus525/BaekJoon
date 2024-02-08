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
    int sum = 0;
    while (n--)
    {
        int v; cin >> v;
        sum += v;
    }

    if (sum > 0) cout << "Right";
    else if (sum == 0) cout << "Stay";
    else cout << "Left";
}

int main()
{
    INPUT();
    solution();
}