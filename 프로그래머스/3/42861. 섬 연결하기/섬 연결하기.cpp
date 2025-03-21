#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct KS
{
    int s, e, v;
};
vector<KS> graph;
int parent[101];

int Find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    
    if (x == y) return true;
    
    parent[x] = y;
    return false;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 0; i < costs.size(); i++)
    {
        int s = costs[i][0], e = costs[i][1], v = costs[i][2];
        graph.push_back({s, e, v});
    }
    sort(graph.begin(), graph.end(), [](KS a, KS b){return a.v < b.v;});
    for (int i = 0; i < n; i++) parent[i] = i;
    
    for (int i = 0; i < graph.size(); i++)
    {
        if (!Union(graph[i].s, graph[i].e))
        {
            answer += graph[i].v;
        }
    }
    
    
    return answer;
}