#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
vector<pii> v;
bool isCity[21][21];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '1')
            {
                v.emplace_back(i, j);
                isCity[i][j] = true;
            }
        }
    }
}

int calc(int x1, int y1, int x2, int y2)
{
    int ans = 0;
    for (auto &pos: v)
    {
        int tempD = min(abs(pos.first - x1) + abs(pos.second - y1),
                        abs(pos.first - x2) + abs(pos.second - y2));
        ans = max(tempD, ans);
    }
    return ans;
}

void solution()
{
    int ans = 2e9;
    for (int x1 = 0; x1 < n; x1++)
        for (int y1 = 0; y1 < m; y1++)
        {
            if (isCity[x1][y1]) continue;
            for (int x2 = x1; x2 < n; x2++)
                for (int y2 = 0; y2 < m; y2++)
                {
                    if (isCity[x2][y2]) continue;
                    if (x1 == x2 && y1 == y2) continue;
                    ans = min(ans, calc(x1, y1, x2, y2));
                }
        }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}