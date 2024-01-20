#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> d, vector<int> p) {
    long long answer = 0;
    
    int dIdx = d.size() - 1;
    int pIdx = p.size() - 1;
    
    while (dIdx >= 0 || pIdx >= 0)
    {
        
        //0 아닐 때까지 idx 옮기기
        while (dIdx >= 0 && !d[dIdx]) dIdx--;
        while (pIdx >= 0 && !p[pIdx]) pIdx--;
        if (dIdx < 0 && pIdx < 0) break;
        //cout << dIdx << " " << pIdx << '\n';
        //ans 갱신
        answer += (max(dIdx, pIdx) + 1) * 2;
        
        //cnt가 0이 되거나 idx가 -1일 때까지 이동
        int cnt = cap;
        while (cnt)
        {
            if (dIdx < 0) break;
            
            if (dIdx >= 0 && !d[dIdx]) dIdx--;
            else d[dIdx]--, cnt--;
        }
        cnt = cap;
        while (cnt)
        {
            if (pIdx < 0) break;
            
            if (pIdx >= 0 && !p[pIdx]) pIdx--;
            else p[pIdx]--, cnt--;
        }
    }
    
    return answer;
}