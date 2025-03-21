#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b)
         {
             return a[1] < b[1];
         });
    
    int cri = routes[0][1];
    for (int i = 1; i < routes.size(); i++)
    {
        if (routes[i][0] <= cri) continue;
        cri = routes[i][1];
        answer++;
    }
    
    return answer;
}