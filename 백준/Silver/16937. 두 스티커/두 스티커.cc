#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int h, w, n;
pii sticker[101];

void INPUT()
{
    IAMFAST
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) cin >> sticker[i].first >> sticker[i].second;
}

void solution()
{
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a = sticker[i].first, b = sticker[i].second;
        int iVal = a * b;
        for (int j = i + 1; j < n; j++)
        {
            int c = sticker[j].first, d = sticker[j].second;
            int jVal = c * d;

            if (max(a, c) <= h && b + d <= w) ans = max(ans, iVal + jVal);
            if (a + c <= h && max(b, d) <= w) ans = max(ans, iVal + jVal);

            if (max(a, d) <= h && b + c <= w) ans = max(ans, iVal + jVal);
            if (a + d <= h && max(b, c) <= w) ans = max(ans, iVal + jVal);

            if (max(b, c) <= h && a + d <= w) ans = max(ans, iVal + jVal);
            if (b + c <= h && max(a, d) <= w) ans = max(ans, iVal + jVal);

            if (max(b, d) <= h && a + c <= w) ans = max(ans, iVal + jVal);
            if (b + d <= h && max(a, c) <= w) ans = max(ans, iVal + jVal);
        }
    }

    cout << ans;

}

int main()
{
    INPUT();
    solution();
}