#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

deque<int> dq;

int solution(string name) {
    int answer = 0;
    
    int len = name.length();
    for (int i = 0; i < len; i++)
        if (name[i] != 'A')
            dq.emplace_back(i);

    
    int moveCnt = len - 1;
    
    for (int i = 0; i < len; i++)
    {
        int up = name[i] - 'A';
        answer += min(up, 26 - up);
        
        int j = i + 1;
        while (j < len && name[j] == 'A') j++;
        
        moveCnt = min(moveCnt, 
                      min(2*i + len - j, i + 2*len - 2*j));
    }
    
    answer += moveCnt;
    return answer;
}