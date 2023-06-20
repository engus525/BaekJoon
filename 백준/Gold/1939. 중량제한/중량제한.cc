#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long ll;
int n,m;
int a,b;
ll c;
vector<pair<int,ll>> graph[10001];
bool visited[10001];
int s,e;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < m ; i++)
    {
        cin >> a >> b >> c;

        bool exist = false;
        for(auto &g : graph[a])
            if(g.first == b)
                g.second = max(g.second, c),
                exist = true;
        for(auto &g : graph[b])
            if(g.first == a)
                g.second = max(g.second, c);

        if(!exist)
        {
            graph[a].emplace_back(b, c);
            graph[b].emplace_back(a, c);
        }
    }
    cin >> s >> e;
}

bool BFS(ll weight)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        if(now == e) return true;

        for(auto &next : graph[now])
        {
            if(visited[next.first]) continue;
            if(next.second < weight) continue;

            visited[next.first] = true;
            q.push(next.first);
        }
    }
    return false;
}

void SOLVE()
{
    ll left = 1, right = 1e9;
    ll ans = 0;
    while(left <= right)
    {
        ll mid = (left+right)/2;

        memset(visited, false, sizeof visited);
        if(BFS(mid)) ans = mid, left = mid+1;
        else right = mid-1;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}