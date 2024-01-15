#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
stack<int> board[31];

int solution(vector<vector<int>> v, vector<int> moves) {
    int answer = 0;
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v.size() - 1; j >= 0; j--)
        {
            if (v[j][i] == 0) break;
            board[i + 1].push(v[j][i]);
        }   
    }

    stack<int> st;
    for (auto m : moves)
    {
        if (board[m].empty()) continue;
        //cout << m << " 에서 " << board[m].top() << " 뺀다.\n";
        
        if (!st.empty() && st.top() == board[m].top())
        {
            answer += 2;
            //cout << "Boom!\n";
            board[m].pop();
            st.pop();
        }
        else
            st.push(board[m].top()),
            board[m].pop();
        
    }
    
    return answer;
}