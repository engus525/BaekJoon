#include <string>
#include <vector>
#include <iostream>

using namespace std;
int minDist[26];

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for (int i = 0; i < 26; i++) minDist[i] = 2e9;
    
    for (auto key : keymap)
    {
        for (int cnt = 0; cnt < key.length(); cnt++)
        {
            int idx = key[cnt] - 'A';
            minDist[idx] = min(minDist[idx], cnt + 1);
        }
    }
    
    //for (int i = 0; i < 26; i++)
        //cout << char('A' + i) << " : " << minDist[i] << "\n";
    
    for (auto target : targets)
    {
        int dist = 0;
        for (auto c : target)
        {
            if (minDist[c - 'A'] == 2e9)
            {
                dist = 2e9;
                break;
            }
            dist += minDist[c - 'A'];
        }
        //cout << "Dist : " << dist << '\n';
        if (dist != 2e9) answer.emplace_back(dist);
        else answer.emplace_back(-1);
    }
    
    return answer;
}