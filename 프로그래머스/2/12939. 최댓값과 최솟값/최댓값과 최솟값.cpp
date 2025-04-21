#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> v;

string solution(string s) {
    string ans = "";
    istringstream iss(s);
    string token;
    while (getline(iss, token, ' '))
        v.emplace_back(stoi(token));
    sort(v.begin(), v.end());
    
    ans += to_string(*min_element(v.begin(), v.end())) + " " 
        + to_string(*max_element(v.begin(), v.end())); 
    return ans;
}