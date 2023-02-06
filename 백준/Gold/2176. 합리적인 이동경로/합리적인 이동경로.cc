#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int a,b,c;

typedef pair<int,int> pii;
vector<pii> graph[1001];
int dist[1001];
int dp[1001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> a >> b >> c,
        graph[a].push_back({b,c}),
        graph[b].push_back({a,c});
}

int IJK()
{
    priority_queue<pii> q;
    q.push({0,2});
    dp[2] = 1; dist[2] = 0;

    while(!q.empty())
    {
        int d = -q.top().first;
        int now = q.top().second;
        q.pop();

        if(d > dist[now]) continue;

        for(int i = 0; i < graph[now].size(); i++)
        {
            int nPos = graph[now][i].first;
            int nDist = graph[now][i].second + d;

            if(nDist < dist[nPos]) dist[nPos] = nDist , q.push({-nDist,nPos});

            if(d > dist[nPos]) dp[now] += dp[nPos];
        }
    }
    return dp[1];
}


void SOLVE()
{
    fill(dist+1,dist+n+1,2e9);
    cout << IJK();
}

int main()
{
    INPUT();
    SOLVE();
}