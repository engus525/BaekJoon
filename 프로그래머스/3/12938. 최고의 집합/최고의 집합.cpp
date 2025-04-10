#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (s < n) return {-1};
    
    vector<int> ans;
    for (int i = 0; i < n - s % n; i++) ans.emplace_back(s / n);
    for (int i = 0; i < s % n; i++) ans.emplace_back(s / n + 1);
    
    
    return ans;
}