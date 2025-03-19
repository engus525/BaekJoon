#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> v;

string solution(vector<int> numbers) {
    string answer = "";
    
    int maxLen = 1;
    for (int i = 0; i < numbers.size(); i++)
    {
        string str = to_string(numbers[i]);
        v.emplace_back(str);
    }
    
    sort(v.begin(), v.end(), [](string a, string b)
         {
             return a + b > b + a;
         });
    
    for (auto str : v)
    {
        answer += str;
    }

    
    
    return (answer[0] == '0') ? "0" : answer;
}