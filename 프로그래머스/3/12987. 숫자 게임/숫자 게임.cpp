#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int> aQ, bQ;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    for (int i = 0; i < A.size(); i++)
        aQ.emplace(A[i]), bQ.emplace(B[i]);
    
    while (!aQ.empty() && !bQ.empty())
    {
        if (aQ.top() < bQ.top())
        {
            answer++;
            aQ.pop(), bQ.pop();
        }
        else if (aQ.top() == bQ.top()) aQ.pop();
        else if (aQ.top() > bQ.top())
        {
            aQ.pop();
        }
    }
    
    return answer;
}