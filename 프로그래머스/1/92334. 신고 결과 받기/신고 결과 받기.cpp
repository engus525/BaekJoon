#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;
map<string, set<string>> report;

vector<int> solution(vector<string> id_list, vector<string> r, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> id_idx;
    for (int i = 0; i < id_list.size(); i++)
        id_idx[id_list[i]] = i;
    
    for (auto p : r)
    {
        stringstream ss(p);
        string a, b;
        ss >> a >> b;
        
        report[b].insert(a);
    }
    
    for (auto r : report)
    {
        
        if (r.second.size() >= k)
            for (auto sec : r.second)
                answer[id_idx[sec]]++;
    }
    
    return answer;
}