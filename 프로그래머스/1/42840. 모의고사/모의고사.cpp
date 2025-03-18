#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> p1 = {1,2,3,4,5};
vector<int> p2 = {2,1,2,3,2,4,2,5};
vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
int score[3];

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int maxScore = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == p1[i % p1.size()]) score[0]++;
        if (answers[i] == p2[i % p2.size()]) score[1]++;
        if (answers[i] == p3[i % p3.size()]) score[2]++;
        maxScore = *max_element(score, score + 3);
    }
    
    for (int i = 0; i < 3; i++)
        if (maxScore == score[i]) answer.emplace_back(i + 1);
    return answer;
}