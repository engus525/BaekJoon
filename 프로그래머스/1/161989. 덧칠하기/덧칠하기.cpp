#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int now = 0;
    for (int sec : section)
    {
        if (now < sec)
        {
            answer++;
            now = sec + m - 1;
        }
    }
    
    return answer;
}