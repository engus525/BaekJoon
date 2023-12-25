#include <string>
#include <iostream>
#include <vector>

using namespace std;
int limit[30];

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int Y = stoi(today.substr(0,4));
    int M = stoi(today.substr(5,2));
    int D = stoi(today.substr(8,2));
    
    for (auto t : terms)
    {
        string lim = t.substr(2);
        limit[t[0] - 'A'] = stoi(lim);
    }
    
    int idx = 0;
    for (auto pri : privacies)
    {
        idx++;
        int y = stoi(pri.substr(0,4));
        int m = stoi(pri.substr(5,2));
        int d = stoi(pri.substr(8,2));
        char kind = pri[11];
        
        int deleteM = m + limit[kind - 'A'];
        y += limit[kind - 'A'] / 12;
        m += limit[kind - 'A'] - 12 * (limit[kind - 'A'] / 12);
        if (m >= 13) y++, m %= 12;
        
        cout << kind << " : " << y << " " << m << " " << d << '\n';
        
        if (y > Y) continue;
        if (y == Y && m > M) continue;
        if (y == Y && m == M && d > D) continue;
        
        answer.emplace_back(idx);
    }
    
    return answer;
}