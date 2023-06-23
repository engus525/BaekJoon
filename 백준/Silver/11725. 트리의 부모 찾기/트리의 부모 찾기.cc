#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int ans[100001];
vector<int> graph[100001];
bool visited[100001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int a,b; cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
}

void BFS()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(auto &g : graph[now])
        {
            if(visited[g]) continue;

            visited[g] = true;
            ans[g] = now;
            q.push(g);
        }
    }
}

void SOLVE()
{
    BFS();
    for(int i = 2; i <= n; i++) cout << ans[i] << '\n';
}

int main()
{
    INPUT();
    SOLVE();
}