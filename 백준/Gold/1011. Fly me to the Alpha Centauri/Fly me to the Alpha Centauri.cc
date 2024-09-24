#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll t, x, y;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        cin >> x >> y;
        double target = y - x;

        int mid = floor(sqrt(target));

        int left = target - mid * mid;

        cout << 2 * mid - 1 + ceil(left / double(mid)) << '\n';

    }
}

int main()
{
    INPUT();
    solution();
}