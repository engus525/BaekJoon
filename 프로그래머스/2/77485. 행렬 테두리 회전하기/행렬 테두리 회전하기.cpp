#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int board[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    //make board
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            board[i][j] = (i - 1) * columns + j;
    
    for (auto qu : queries)
    {
        int a = qu[0], b = qu[1], c = qu[2], d = qu[3];
        
        int minV = 2e9;
        
        queue<int> q;
        q.emplace(board[a][d]); minV = min(minV, board[a][d]);
        for (int i = d; i > b; i--)
            board[a][i] = board[a][i - 1],
            minV = min(minV, board[a][i]);
        
        q.emplace(board[c][d]); minV = min(minV, board[c][d]);
        for (int i = c; i > a; i--) 
            board[i][d] = board[i - 1][d],
            minV = min(minV, board[i][d]);
        board[a + 1][d] = q.front(), q.pop();
        
        q.emplace(board[c][b]); minV = min(minV, board[c][b]);
        for (int i = b; i < d; i++)
            board[c][i] = board[c][i + 1],
            minV = min(minV, board[c][i]);
        board[c][d - 1] = q.front(), q.pop();
        
        for (int i = a; i < c; i++)
            board[i][b] = board[i + 1][b],
            minV = min(minV, board[i][b]);
        board[c - 1][b] = q.front();
        
        answer.emplace_back(minV);
    }
    
    return answer;
}