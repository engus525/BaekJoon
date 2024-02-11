#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
unordered_map<string, int> ranks;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    for (int i = 0; i < players.size(); i++) ranks.insert({players[i], i});
    for (auto call : callings)
    {
        int me = ranks[call];
        string front = players[me - 1];
        
        players[me - 1] = players[me];
        players[me] = front;
        
        ranks[call] = me - 1;
        ranks[front] = me;
    }
    
    for (auto p : players) answer.emplace_back(p);
    return answer;
}