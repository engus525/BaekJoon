#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int v,e;
int a,b,c;
typedef pair<int,int> pii;
vector<pii> graph[10001];
bool visited[10001];

void INPUT()
{
    IAMFAST
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
    }
}

int Prim()
{
    int ans = 0;

    priority_queue<pii> pq;
    for(auto &i : graph[1])
        pq.push({-i.second,i.first});
    visited[1] = true;

    while(!pq.empty())
    {
        auto [dist1,now] = pq.top();
        pq.pop();

        if(visited[now]) continue;
        visited[now] = true;

        ans += -dist1;

        for(auto &[next,dist2] : graph[now])
            pq.push({-dist2,next});
    }
    return ans;
}

void SOLVE()
{
    cout << Prim();
}

int main()
{
    INPUT();
    SOLVE();
}