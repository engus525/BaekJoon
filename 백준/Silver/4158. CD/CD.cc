#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int a[1000001], b[1000001];

void INPUT()
{
    IAMFAST
}

void solution()
{
    while (cin >> n >> m)
    {
        if (n + m == 0) break;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        int ans = 0;

        int l = 0, r = 0;
        while (l < n && r < m)
        {
            if (a[l] == b[r]) ans++;

            if (a[l] < b[r]) l++;
            else if (a[l] > b[r]) r++;
            else l++, r++;
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}