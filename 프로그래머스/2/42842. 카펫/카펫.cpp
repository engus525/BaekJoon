#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 1; i <= brown + yellow; i++)
    {
        int w = (brown + yellow) / i;
        if ((brown + yellow) % i) continue;
        int h = i;
        if (w < h) break;
        
        int b = 2*w + 2*h - 4;
        int y = (w-2) * (h-2);
        if (b == brown && y == yellow)
        {
            answer = {w, h};
            // cout << w << " " << h << '\n';
        }
    }
    
    return answer;
}