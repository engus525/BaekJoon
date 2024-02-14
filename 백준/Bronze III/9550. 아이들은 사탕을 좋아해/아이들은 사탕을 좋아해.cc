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
        int n, k;
        cin >> n >> k;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int num; cin >> num;
            ans += num / k;
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}