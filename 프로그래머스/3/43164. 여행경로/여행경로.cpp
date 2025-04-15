#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<string>> graph;
bool visited[10001];
vector<string> ans;
int routeSize;

bool dfs(string now)
{
    // cout << "Insert " << now << " and size is " << ans.size() << '\n';
    ans.emplace_back(now);
    if (ans.size() == routeSize) return true;
    
    
    for (int i = 0; i < graph.size(); i++)
    {
        string s = graph[i][0], next = graph[i][1];
        if (now != s) continue;
        if (visited[i]) continue;
        
        visited[i] = true;
        if (dfs(next)) return true;
        visited[i] = false;
    }
    
    // cout << "Pop " << ans.back() << '\n';
    ans.pop_back();
    return false;
    
}


vector<string> solution(vector<vector<string>> tv) {
    graph = tv;
    routeSize = graph.size() + 1;
    sort(graph.begin(), graph.end());
    
    dfs("ICN");
    
    return ans;
}