#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for (auto val : scoville) pq.emplace(val);
    
    while (pq.top() < K)
    {
        if (pq.size() == 1) return -1;
        
        ll first = pq.top(); pq.pop();
        ll second = pq.top(); pq.pop();
        // cout << first << " " << second << '\n';
        pq.emplace(first + 2 * second);
        
        answer++;
    }
    
    return answer;
}