#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int d[50001];
int tot = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i], tot += d[i];
}


void solution()
{
    int ans = 0;

    int l = 0, r = 1;
    int d1 = d[0];
    int d2 = tot - d1;

    while (l < n)
    {
        ans = max(ans, min(d1, d2));

        if (d1 >= d2) d1 -= d[l], d2 += d[l++];
        else d1 += d[r], d2 -= d[r++], r %= n;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}