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

int n, m;
int cnt[2001];
vector<int> swit[2001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int num; cin >> num;
        for (int j = 0; j < num; j++)
        {
            int lamp; cin >> lamp;
            cnt[lamp]++;
            swit[i].emplace_back(lamp);
        }
    }
}

void solution()
{

    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < swit[i].size(); j++) cnt[swit[i][j]]--;
        bool allLive = true;
        for (int j = 1; j <= m; j++)
            if (cnt[j] <= 0)
            {
                allLive = false;
                break;
            }
        if (allLive)
        {
            ans = true;
            break;
        }
        for (int j = 0; j < swit[i].size(); j++) cnt[swit[i][j]]++;
    }

    cout << ans;
}


int main()
{
    INPUT();
    solution();
}