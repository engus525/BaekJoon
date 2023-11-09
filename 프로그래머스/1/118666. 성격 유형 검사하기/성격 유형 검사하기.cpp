#include <string>
#include <vector>

using namespace std;
int score[30];

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] > 4) score[survey[i][1] - 'A'] += choices[i] - 4;
        else score[survey[i][0] - 'A'] += 4 - choices[i];
    }
    
    (score['R' - 'A'] >= score['T' - 'A']) ? answer += "R" : answer += "T";
    (score['C' - 'A'] >= score['F' - 'A']) ? answer += "C" : answer += "F";
    (score['J' - 'A'] >= score['M' - 'A']) ? answer += "J" : answer += "M";
    (score['A' - 'A'] >= score['N' - 'A']) ? answer += "A" : answer += "N";
    
    
    return answer;
}