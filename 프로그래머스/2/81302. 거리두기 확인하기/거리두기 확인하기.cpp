#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

char graph[5][5][5];

pii check1[2] = {{1,0},
                {0,1}};

pii check2[5] = {{1,-1},
                {2,0},
                {1,1},
                {0,2},
                {-1,1}};


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < places.size(); i++)
        for (int j = 0; j < places[i].size(); j++)
            for (int k = 0; k < places[i][j].length(); k++)
                graph[i][j][k] = places[i][j][k];
    
    for (int i = 0; i < places.size(); i++)
    {
        bool good = true;
        for (int j = 0; j < places[i].size(); j++)
        {
            for (int k = 0; k < places[i][j].length(); k++)
            {
                if (graph[i][j][k] != 'P') continue;
                
                /* check1 */
                for (int d = 0; d < 2; d++)
                {
                    int nx = j + check1[d].first;
                    int ny = k + check1[d].second;
                    if (nx > 4 || ny > 4) continue;
                    
                    if (graph[i][nx][ny] == 'P') good = false;
                }
                if (!good) break;
                
                
                /* check2 */
            
                for (int d = 0; d < 5; d++)
                {
                    int nx = j + check2[d].first;
                    int ny = k + check2[d].second;
                    
                    if (nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
                    
                    //직선으로 2칸 떨어진 곳
                    if (check2[d].first == 2 || check2[d].second == 2)
                    {
                        int x = j + check2[d].first / 2;
                        int y = k + check2[d].second / 2;
                        if (graph[i][nx][ny] == 'P' && graph[i][x][y] == 'O') good = false;
                    }
                    
                    //대각선
                    else
                    {
                        int x1 = j;
                        int y1 = ny;
                        int x2 = nx;
                        int y2 = k;
                        
                        
                        if (graph[i][nx][ny] != 'P') continue;
                        if (graph[i][x1][y1] == 'O' || graph[i][x2][y2] == 'O') good = false;
                    }
                }
                if (!good) break;
                

            }
            if (!good) break;
        }
        answer.emplace_back(good);
    }
    
    return answer;
}