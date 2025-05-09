#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int aIdx = 0;
    for (int bIdx = 0; bIdx < B.size(); bIdx++)
        if (A[aIdx] < B[bIdx]) answer++, aIdx++;
    
    return answer;
}