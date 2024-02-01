#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<char> board1[17];
    for (int i = 0; i < n; i++)
    {
        int a1 = arr1[i];
        stack<char> s1;
        
        while (a1 / 2)
        {
            if (a1 % 2) s1.push('#');
            else s1.push(' ');
            a1 /= 2;
        }
        if (a1) s1.push('#');
        while (s1.size() < n) s1.push(' ');
        
        while (!s1.empty()) board1[i].emplace_back(s1.top()), s1.pop();
        // for (auto b : board1[i]) cout << b;
        // cout << '\n';
        
    }
    
    vector<char> board2[17];
    for (int i = 0; i < n; i++)
    {
        int a1 = arr2[i];
        stack<char> s1;
        
        while (a1 / 2)
        {
            if (a1 % 2) s1.push('#');
            else s1.push(' ');
            a1 /= 2;
        }
        if (a1) s1.push('#');
        while (s1.size() < n) s1.push(' ');
        
        while (!s1.empty()) board2[i].emplace_back(s1.top()), s1.pop();
        // for (auto b : board2[i]) cout << b;
        // cout << '\n';
    }
    
    for (int i = 0; i < n; i++)
    {
        string str;
        for (int j = 0; j < n; j++)
        {
            if (board1[i][j] == '#' || board2[i][j] == '#') str += '#';
            else str += ' ';
        }
        answer.emplace_back(str);
    }
    
    return answer;
}