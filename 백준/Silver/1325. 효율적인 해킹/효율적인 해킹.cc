#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
vector<int> graph[10001];
bool visited[10001];
typedef pair<int,int> pii;
vector<pii> ans = {{-1, -1}};

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        graph[b].push_back(a);
    }
}

int DFS(int now)
{
    if(visited[now]) return 0;
    visited[now] = true;

    int cnt = 1;
    for(auto next : graph[now])
        cnt += DFS(next);
    return cnt;
}

void SOLVE()
{
    for(int i = 1; i <= n; i++)
    {
        memset(visited,false,sizeof visited);
        int temp = DFS(i);
        if(ans[0].second < temp)
        {
            ans.clear();
            ans.emplace_back(i,temp);
        }
        else if(ans[0].second == temp) ans.emplace_back(i,temp);
    }

    for(auto i : ans)
        cout << i.first << " ";
}

int main()
{
    INPUT();
    SOLVE();
}