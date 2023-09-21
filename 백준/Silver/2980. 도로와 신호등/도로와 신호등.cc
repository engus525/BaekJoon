#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, l;
int d, r, g;

void INPUT()
{
    IAMFAST
    cin >> n >> l;
}


void solution()
{
    int ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        ans += a - now;
        now = a;
        while (!(b <= ans % (b + c) && ans % (b + c) <= (b + c - 1))) ans++;
    }
    ans += l - now;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}