#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
string str;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
}

void solution()
{
    int ans = 0;
    while (n--)
    {
        cin >> str;

        int count = 0;
        for (int i = 0; i < m; i++)
            if (str[i] == 'O') count++;

        if (count > m / 2) ans++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}