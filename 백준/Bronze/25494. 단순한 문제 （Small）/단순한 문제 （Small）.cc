#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t, a, b, c;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        cin >> a >> b >> c;

        int ans = 0;
        for (int x = 1; x <= a; x++)
            for (int y = 1; y <= b; y++)
                for (int z = 1; z <= c; z++)
                    if (x % y == y % z && y % z == z % x) ans++;
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}