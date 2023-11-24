#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;
typedef pair<int,int> pii;

map<int, pii> pad;
pii lpos = {3,0}, rpos = {3,2};

void makePad()
{
    pad.insert({1,{0,0}});
    pad.insert({2,{0,1}});
    pad.insert({3,{0,2}});
    pad.insert({4,{1,0}});
    pad.insert({5,{1,1}});
    pad.insert({6,{1,2}});
    pad.insert({7,{2,0}});
    pad.insert({8,{2,1}});
    pad.insert({9,{2,2}});
    pad.insert({0,{3,1}});
}

int calDist(pii pos, int num)
{
    return abs(pos.first - pad[num].first) + abs(pos.second - pad[num].second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    makePad();
    
    for (auto &num : numbers)
    {
        if (num == 1 || num == 4 || num == 7)
            answer += 'L', lpos = pad[num];
        
        else if (num == 3 || num == 6 || num == 9)
            answer += 'R', rpos = pad[num];
        
        else
        {
            int ldist = calDist(lpos, num);
            int rdist = calDist(rpos, num);
            
            if (ldist == rdist)
                (hand == "right") ? (answer += 'R', rpos = pad[num]) : (answer += 'L', lpos = pad[num]);
            else if (ldist > rdist) answer += 'R', rpos = pad[num];
            else answer += 'L', lpos = pad[num];
        }
    }
    
    return answer;
}