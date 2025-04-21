#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int solution(vector<int> A, vector<int> B)
{
    int ans = 0;

    priority_queue<int> maxHeap(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<>> minHeap(B.begin(), B.end());
    
    while (!maxHeap.empty()) ans += maxHeap.top() * minHeap.top(), maxHeap.pop(), minHeap.pop();

    return ans;
}