#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> M;

vector<int> solution(vector<string> name, vector<int> point, vector<vector<string>> photo) {
    vector<int> answer;
    
    for (int i = 0; i < name.size(); i++)
        M.insert({name[i], point[i]});
    
    for (auto v : photo)
    {
        int sum = 0;
        for (auto p : v)
            sum += M[p];
        answer.emplace_back(sum);
    }
    
    return answer;
}