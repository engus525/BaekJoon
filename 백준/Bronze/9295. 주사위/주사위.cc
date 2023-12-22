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
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << "Case " << i << ": " << a + b << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}