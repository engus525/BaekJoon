#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> v, int k) {
    int answer = 0;
    
    int l = 1, r = *max_element(v.begin(), v.end());
    while (l <= r)
    {
        int mid = (l + r) / 2;
        
        int len = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > mid) continue;
            
            int tempLen = 1;
            while (i < v.size() - 1 && v[i + 1] <= mid) tempLen++, i++;
            
            len = max(len, tempLen);
        }
        
        // cout << "mid : " << mid << ", len : " << len << '\n';
        if (len < k) l = mid + 1;
        else answer = mid, r = mid - 1;
        
    }
    
    return answer;
}