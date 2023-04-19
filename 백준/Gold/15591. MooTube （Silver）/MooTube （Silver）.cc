#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,t;
vector<int> graph[5001];
int dist[5001][5001];
int k,v;

void INPUT()
{
    IAMFAST
    cin >> n >> t;
    for(int i = 0; i < n-1; i++)
    {
        int p,q,r; cin>>p>>q>>r;
        graph[p].emplace_back(q);
        graph[q].emplace_back(p);
        dist[p][q] = r;
        dist[q][p] = r;
    }
}

int BFS(int x)
{
    int rtn = 0;

    bool visited[n+1];
    memset(visited,false,sizeof visited);
    visited[x] = true;

    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if(visited[next]) continue;
            if(dist[now][next] < k) continue;

            rtn++;
            visited[next] = true;
            q.push(next);
        }
    }
    return rtn;
}


void SOLVE()
{

    while(t--)
    {
        cin >> k >> v;
        cout << BFS(v) << '\n';
    }

}

int main()
{
    INPUT();
    SOLVE();
}
