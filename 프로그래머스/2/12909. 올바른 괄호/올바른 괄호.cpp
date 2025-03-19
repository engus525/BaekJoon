#include <string>
#include <iostream>
#include <stack>

using namespace std;

stack<char> st;

bool solution(string s)
{
    bool answer = true;
    
    for (auto c : s)
    {
        if (c == '(') st.emplace(c);
        else
        {
            if (st.empty()) return false;
            else if (st.top() == '(') st.pop();
        }
    }
    if (!st.empty()) return false;

    return answer;
}