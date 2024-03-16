#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int h[51];
int cnt[51];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
}

void solution()
{
    for (int i = 0; i < n - 1; i++)
    {
        double maxV = -2e9;
        for (int j = i + 1; j < n; j++)
        {
            double v = (h[i] - h[j]) / double (i - j);
            if (maxV >= v) continue;

            cnt[i]++, cnt[j]++;
            maxV = v;
        }
    }

    cout << *max_element(cnt, cnt + n);
}

int main()
{
    INPUT();
    solution();
}