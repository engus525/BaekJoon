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
        int n, m;
        cin >> n >> m;

        int a, b;
        for (int i = 0; i < m; i++)
            cin >> a >> b;

        cout << n - 1 << '\n';
    }

}

int main()
{
    INPUT();
    solution();
}