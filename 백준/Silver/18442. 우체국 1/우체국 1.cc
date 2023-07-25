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

ll v, p, l;
vector<ll> town;
vector<ll> office(21);
ll minDist = ll(2e60);
vector<ll> ans(21);

void INPUT()
{
    IAMFAST
    cin >> v >> p >> l;
    for (int i = 0; i < v; i++)
    {
        ll pos;
        cin >> pos;
        town.emplace_back(pos);
    }
}

void setAns()
{
    ll dist = 0;
    vector<ll> tempAns;
    for (int i = 0; i < v; i++)
    {
        //현재 마을에서 가장 가까운 우체국 거리
        ll temp = ll(2e60);
        for (int j = 0; j < p; j++)
        {
            temp = min(temp, min(abs(town[i] - office[j]),
                                 l - abs(town[i] - office[j])));
        }
        dist += temp;
    }

    if (minDist > dist) minDist = dist, ans = office;
}

void setComb(int depth, int start)
{
    if (depth == p)
    {
        setAns();
        return;
    }

    for (int i = start; i < v; i++)
    {
        office[depth] = town[i];
        setComb(depth + 1, i + 1);
    }
}

void solution()
{
    setComb(0, 0);
    cout << minDist << '\n';
    for (int i = 0; i < p; i++) cout << ans[i] << " ";
//    for (auto &a : ans) cout << a << " ";
}

int main()
{
    INPUT();
    solution();
}