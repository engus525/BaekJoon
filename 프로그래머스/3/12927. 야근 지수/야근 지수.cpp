#include <string>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long ll;

using namespace std;

ll solution(int n, vector<int> v) {
    ll answer = 0;
    
    priority_queue<ll> pq;
    for (auto val : v) pq.emplace(val);
    
    while (n--) pq.emplace(pq.top() - 1), pq.pop();
    
    if (pq.top() <= 0) return 0;
    while (!pq.empty()) answer += pq.top() * pq.top(), pq.pop();
    return answer;
}