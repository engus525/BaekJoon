#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <thread>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
int cnt[401];

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        memset(cnt, 0, sizeof cnt);
        int n;
        cin >> n;
        vector<pair<pii, bool>> v;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int s, e;
            cin >> s >> e;
            if (s > e) swap(s, e);
            int left = (s % 2) ? s : s - 1;
            int right = (e % 2) ? e + 1 : e;
            for (int j = left; j <= right; j++)
            {
                cnt[j]++;
                ans = max(ans, cnt[j]);
            }
        }

        cout << ans * 10 << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}
/**
10
6
9 10
2 3
100 110
5 6
7 8
1 10
6
9 10
1 10
2 3
100 110
5 6
7 8
5
1 2
2 3
3 4
4 5
5 6
*/