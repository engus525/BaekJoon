#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <limits.h>
#include <vector>
#include <math.h>
#include <stack>
#include <bitset>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cstdlib>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pli pair<ll, int>
#define make_unique(v) sort(all(v)), v.erase(unique(all(v), v.end())
typedef long long ll;
using namespace std;

int V,E,K,u,v,range;
ll w,price[2];
vector<int> arr[100001];
queue<pii> infest;
int chk[100001];
priority_queue<pli,vector<pli>,greater<pli>> pq;
vector<ll> dist(100001,LONG_LONG_MAX);

void bfs(){
    while(!infest.empty()){
        int here = infest.front().first;
        int cnt = infest.front().second;
        infest.pop();
        if(cnt==range)continue;
        
        for(auto there : arr[here]){
            if(!chk[there]){
               chk[there]=1;
               infest.push({there,cnt+1});
            }
        }
    }
}

void dijkstra(){
    pq.push({0LL,1});
    dist[1]=0LL;
    
    while(!pq.empty()){
        ll cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here]<cost) continue;
        
        for(auto there : arr[here]){
            int nextnode = there;
            ll nextcost = price[chk[there]] + cost;
            if(chk[nextnode]==2)continue;
            if(dist[nextnode]>nextcost){
                dist[nextnode]=nextcost;
                pq.push({nextcost,nextnode});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>V>>E>>K>>range;
    cin>>price[0]>>price[1];
    
    for(int i=0;i<K;i++){
        cin>>u;
        infest.push({u,0});
        chk[u]=2;
    }
    
    for(int i=0;i<E;i++){
        cin>>u>>v;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }
        
    bfs();
    dijkstra();
    cout<<dist[V]-price[chk[V]];
    return 0;
}