#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, a, b;

void INPUT()
{
    IAMFAST
    cin >> n >> a >> b;
}

void solution()
{
    int ans = 1;
    while ((a + 1) / 2 != (b + 1) / 2)
    {
        ans++;
        a++, a /= 2;
        b++, b /= 2;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}