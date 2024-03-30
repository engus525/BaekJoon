#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int tree[100001];
int gap[100001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> tree[i];
}

int gcd(int a, int b)
{
    int A = max(a, b);
    int B = min(a, b);

    while (B)
    {
        int r = A % B;
        A = B, B = r;
    }
    return A;
}

void solution()
{
    for (int i = 1; i < n; i++) gap[i - 1] = tree[i] - tree[i - 1];

    int val = gcd(gap[0], gap[1]);
    for (int i = 2; i < n - 1; i++)
        val = gcd(val, gap[i]);

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += gap[i] / val - 1;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}