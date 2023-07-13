#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m,k,start;
vector<int> graph[300001];
int visited[300001];
vector<int> ans;

void INPUT()
{
    IAMFAST
    cin >> n >> m >> k >> start;
    for(int i = 0; i < m; i++)
    {
        int s,e; cin >> s >> e;
        graph[s].emplace_back(e);
    }
}

void BFS()
{
    queue<int> q;
    q.emplace(start);
    visited[start] = 0;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        if(visited[now] == k) ans.emplace_back(now);
        if(visited[now] > k) return;

        for(auto &next : graph[now])
        {
            if(visited[next] != -1) continue;

            visited[next] = visited[now] + 1;
            q.emplace(next);
        }
    }
}

void solution()
{
    memset(visited,-1,sizeof visited);
    BFS();
    sort(ans.begin(),ans.end());

    if(ans.empty()) cout << -1;
    else
        for(auto &a : ans)
            cout << a << '\n';
}

int main()
{
    INPUT();
    solution();
}