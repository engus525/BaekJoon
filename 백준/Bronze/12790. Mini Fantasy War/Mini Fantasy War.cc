#include <iostream>
#include <string>
#include <algorithm>

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
        int a, b, c, d, x, y, w, z;
        cin >> a >> b >> c >> d >> x >> y >> w >> z;

        cout << max(1, a + x) + 5 * max(1, b + y) + 2 * max(0, (c + w)) + 2 * (d + z) << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}