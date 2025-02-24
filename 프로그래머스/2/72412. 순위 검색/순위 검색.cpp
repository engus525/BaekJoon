#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory.h>
#include <algorithm>
#include <unordered_map>


using namespace std;

vector<int> v[4][3][3][3];


// Convert To Int
int cti(string str)
{
    if (str == "-") return 0;
    else if (str == "java" || str == "backend"
             || str == "junior" || str == "chicken") return 1;
    else if (str == "python" || str == "frontend"
             || str == "senior" || str == "pizza") return 2;
    else return 3; // cpp
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for (int i = 0; i < info.size(); i++)
    {
        stringstream ss(info[i]);
        string a, b, c, d; int score;
        ss >> a >> b >> c >> d >> score;
        int i1 = cti(a), i2 = cti(b), i3 = cti(c), i4 = cti(d);
        v[i1][i2][i3][i4].push_back(score);
        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                for (int z = 0; z < 2; z++)
                {
                    for (int w = 0; w < 2; w++)
                    {
                        int n1 = i1, n2 = i2, n3 = i3, n4 = i4;
                        if (x) n1 = 0;
                        if (y) n2 = 0;
                        if (z) n3 = 0;
                        if (w) n4 = 0;
                        if (x || y || z || w) v[n1][n2][n3][n4].push_back(score);
                    }
                }
            }
        }
    }
    
    for (int i1 = 0; i1 < 4; i1++)
        for (int i2 = 0; i2 < 3; i2++)
            for (int i3 = 0; i3 < 3; i3++)
            {
                for (int i4 = 0; i4 < 3; i4++)
                {
                    sort(v[i1][i2][i3][i4].begin(), v[i1][i2][i3][i4].end());
                    // cout << i1 << " " << i2 << " " << i3 << " " << i4 << '\n';
                    // for (auto val : v[i1][i2][i3][i4]) cout << val << " ";
                    // cout << '\n';
                }
            }
    
    for (int i = 0; i < query.size(); i++)
    {
        stringstream ss(query[i]);
        string a, and1, b, and2, c, and3, d; int score;
        ss >> a >> and1 >> b >> and2 >> c >> and3 >> d >> score;
        int i1 = cti(a), i2 = cti(b), i3 = cti(c), i4 = cti(d);
        // cout << i1 << " " << i2 << " " << i3 << " " << i4 << '\n';
        answer.push_back(v[i1][i2][i3][i4].size() 
            - (lower_bound(v[i1][i2][i3][i4].begin(),
                          v[i1][i2][i3][i4].end(),
                          score) - v[i1][i2][i3][i4].begin()));
    }
    
    return answer;
}