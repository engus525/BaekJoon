#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

priority_queue<int> pq;
queue<pii> q;

int solution(vector<int> priorityV, int location) {
    int answer = 1;
    for (int i = 0; i < priorityV.size(); i++)
    {
        pq.emplace(priorityV[i]);
        q.emplace(priorityV[i], i);
    }
    
    while (true)
    {
        if (pq.top() == q.front().first)
        {
            if (q.front().second == location) break;
            
            // cout << pq.top() << "처리할 차례인데, 주인공은 아님\n";
            pq.pop();
            q.pop();
            answer++;
            continue;
        }
        else
        {
            // cout << pq.top() << "차례임. " << q.front().first << " 들어가\n";
            q.emplace(q.front());
            q.pop();
            continue;
        }
        
    }
    
    return answer;
}