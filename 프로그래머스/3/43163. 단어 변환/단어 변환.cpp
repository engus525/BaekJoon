#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
string s, e;
unordered_set<string> S;

bool isNext(const string &now, const string &next)
{
    int diffCnt = 0;
    for (int i = 0; i < now.length(); i++)
        if (now[i] != next[i])
            diffCnt++;
    
    if (diffCnt == 1) return true;
    return false;
}

int bfs(vector<string> &v)
{
    queue<pair<string, int>> q;
    q.emplace(s, 0);
    S.emplace(s);
    
    while (!q.empty())
    {
        auto [now, dist] = q.front();
        q.pop();
        
        if (now == e) return dist;
        
        for (int i = 0; i < v.size(); i++)
        {
            string next = v[i];
            if (S.find(next) != S.end()) continue;
            if (!isNext(now, next)) continue;
            
            q.emplace(next, dist + 1);
            S.emplace(next);
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    s = begin, e = target;
    int answer = 0;
    
    return bfs(words);
}