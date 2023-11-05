#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int road[1000005];
int shoutCnt = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    bool cont = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> road[i];
        if (road[i])
        {
            if (cont) continue;
            else shoutCnt++, cont = true;
        }
        else cont = false;
    }
}

void solution()
{
    while (m--)
    {
        int comm;
        cin >> comm;

        if (comm)
        {
            int idx;
            cin >> idx;

            if (road[idx]) continue;
            if (road[idx - 1] && road[idx + 1]) shoutCnt--;
            if (!((road[idx - 1] || road[idx + 1]) || road[idx])) shoutCnt++;

            road[idx] = 1;
        }
        else cout << shoutCnt << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}