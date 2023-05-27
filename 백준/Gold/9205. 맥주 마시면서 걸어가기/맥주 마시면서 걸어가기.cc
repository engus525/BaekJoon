#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t,n;
typedef pair<int,int> pii;
vector<pii> graph;
vector<int> map[105];
bool visited[105];

void INPUT()
{
    IAMFAST
    cin >> t;
}

int Dist(int a,int b)
{
    return abs(graph[a].first-graph[b].first)+
            abs(graph[a].second-graph[b].second);
}

void setGraph()
{
    for(int i = 0; i < graph.size()-1; i++)
        for(int j = i+1; j < graph.size(); j++)
            if(Dist(i,j) <= 1000)
                map[i].emplace_back(j),
                map[j].emplace_back(i);
}

string BFS()
{
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        if(now == n+1) return "happy\n";

        for(auto i : map[now])
        {
            if(visited[i]) continue;
            visited[i] = true;
            q.push(i);
        }
    }
    return "sad\n";
}

void Init()
{
    memset(visited,false,sizeof visited);
    graph.clear();
    for(auto &i : map) i.clear();
}

void SOLVE()
{
    while(t--)
    {
        Init();

        //input
        cin >> n;
        for(int i = 0; i < n+2; i++)
        {
            int x,y; cin >> x >> y;
            graph.emplace_back(x,y);
        }

        setGraph();

        cout << BFS();
    }
}

int main()
{
    INPUT();
    SOLVE();
}