#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t;
int n,d,c;
int a,b,s;
typedef pair<int,int> pii;
vector<pii> graph[10001];
int dist[10001];

void INPUT()
{
    IAMFAST
    cin >> t;
}

void Init()
{
    for(int i = 1; i <= 10000; i++) graph[i].clear();
    for(int i = 1; i <= 10000; i++) dist[i] = 2e9;
}

void ijk()
{
    priority_queue<pii> pq;
    pq.push({0,c});
    dist[c] = 0;

    while(!pq.empty())
    {
        auto [d1,now] = pq.top();
        d1 = -d1;
        pq.pop();

        if(d1 > dist[now]) continue;

        for(auto i : graph[now])
        {
            auto [next,d2] = i;
            if(d1+d2 >= dist[next]) continue;

            pq.push({-(d1+d2),next});
            dist[next] = d1+d2;
        }
    }
}

void SOLVE()
{
    while(t--)
    {
        Init();
        cin >> n >> d >> c;
        for(int i = 0; i < d; i++)
        {
            cin >> a >> b >> s;
            graph[b].emplace_back(a,s);
        }
        ijk();

        //output
        pii ans = {0,0};
        for(int i = 1; i <= n; i++)
            if(dist[i] != 2e9)
                ans.first++,
                ans.second = max(ans.second,dist[i]);
        cout << ans.first << " " << ans.second << '\n';

    }
}

int main()
{
    INPUT();
    SOLVE();
}