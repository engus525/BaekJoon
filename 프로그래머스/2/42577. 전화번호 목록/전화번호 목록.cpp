#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool finished[1000001];
vector<int> lenV;
unordered_set<string> S;

bool solution(vector<string> phoneV) {
    sort(phoneV.begin(), phoneV.end());
    
    for (int i = 0; i < phoneV.size() - 1; i++)
    {
        string phone = phoneV[i];
        if (phone == phoneV[i + 1].substr(0, phone.length()))
            return false;
    }
    
    return true;
}