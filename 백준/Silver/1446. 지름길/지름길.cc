#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,d;
typedef pair<int,int> pii;
vector<pii> graph[10001];
int dist[10001];

void INPUT()
{
    IAMFAST
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        graph[a].emplace_back(b,min(b-a,c));
    }
}

int ijk()
{
    for(int i = 0; i < d; i++)
        graph[i].emplace_back(i+1,1);

    fill(dist,dist+d+1,2e9);
    priority_queue<pii> pq;
    pq.push({0,0});
    dist[0] = 0;

    while(!pq.empty())
    {
        auto [d1,now] = pq.top();
        d1 = -d1;
        pq.pop();

        for(auto i : graph[now])
        {
            auto [next,d2] = i;
            if(d1+d2 >= dist[next]) continue;

            pq.push({-(d1+d2),next});
            dist[next] = d1+d2;
        }
    }
    return dist[d];
}

void SOLVE()
{
    cout << ijk();
}

int main()
{
    INPUT();
    SOLVE();
}