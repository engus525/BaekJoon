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

int n,m, j;

void INPUT()
{
    IAMFAST
    cin >> n >> m >> j;
}

void solution()
{
    int left = 1, right = m;

    int ans = 0;
    while(j--)
    {
        int drop;
        cin >> drop;

        if (left <= drop && drop <= right) continue;
        else if (drop < left)
        {
            int dist = left - drop;
            ans += dist;
            left -= dist;
            right -= dist;
        }
        else
        {
            int dist = drop - right;
            ans += dist;
            left += dist;
            right += dist;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}