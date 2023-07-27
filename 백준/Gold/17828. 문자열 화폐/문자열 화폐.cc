#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

int n, x;

void INPUT()
{
    IAMFAST
    cin >> n >> x;
}


void solution()
{
    string ans;
    for(int i = n; i >= 1; i--)
    {
        int limit = 26 * i;
        if (x > limit || x == 0)
        {
            ans = "!";
            break;
        }

        int gap = limit - x;
        if (gap > 26) ans += "A", x--;
        else
        {
            int alpha = (26 - gap) - 1 + 'A';
            ans += char(alpha), x -= alpha - 'A' + 1;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}