#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    queue<int> q;
    for (auto val : arr)
    {
        if (q.empty())
        {
            // cout << val << " in\n";
            q.emplace(val);
        }
        else if (q.back() == val)
        {
            // cout << val << " pass\n";
            
            continue;
        }
        else
        {
            // cout << val << " in\n";
            q.emplace(val);
        }
    }
    
    while (!q.empty()) answer.emplace_back(q.front()), q.pop();

    return answer;
}