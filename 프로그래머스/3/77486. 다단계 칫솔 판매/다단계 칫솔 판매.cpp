#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;
unordered_map<string, string> graph;
vector<string> sellerV;
vector<int> amountV;
unordered_map<string, int> ansM;
vector<int> ans;
int cnt = 0;

void bfs(string start)
{
    queue<string> q;
    q.emplace(start);
    int money = amountV[cnt] * 100;
    
    while (!q.empty())
    {
        string now = q.front();
        q.pop();
        
        if (graph.find(now) == graph.end()) continue;
        if (money < 10)
        {
            ansM[now] += money;
            continue;
        }
        string next = graph[now];
        
        ansM[now] += money - int(money * 0.1);
        // cout << now << " : " << ansM[now] << " , ";
        // cout << next << " : " << ansM[next] << '\n';
        money -= money - int(money * 0.1);
        // cout << "up money : " << money << '\n';
        q.emplace(next);
        
    }
}

vector<int> solution(vector<string> leafV, vector<string> parentV, vector<string> seller, vector<int> amount) {
    sellerV = seller, amountV = amount;
    
    for (int i = 0; i < leafV.size(); i++)
    {
        graph[leafV[i]] = parentV[i];
    }
    
    for (auto s : sellerV) bfs(s), cnt++;
    
    for (auto name : leafV) ans.emplace_back(ansM[name]);
    return ans;
}