#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int idx[11];
vector<int> A, B;
vector<int> aSum, bSum;
vector<vector<int>> dice;

void calcSum(vector<int> &v, bool isA, int depth, int sum)
{
    if (depth == v.size())
    {
        if (isA) aSum.emplace_back(sum);
        else bSum.emplace_back(sum);
        return;
    }
    
    for (int i = 0; i < 6; i++)
        calcSum(v, isA, depth + 1, sum + dice[v[depth]][i]);
    return;
}

void calcWin()
{
    aSum.clear(), bSum.clear();
    calcSum(A, true, 0, 0), calcSum(B, false, 0, 0);
    return;
}

vector<int> solution(vector<vector<int>> d) {
    n = d.size();
    vector<int> answer(n / 2);
    dice.resize(n + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 6; j++)
            dice[i].emplace_back(d[i][j]);
    
    int sub[11];
    fill(sub, sub + n, 1);
    for (int i = 0; i < n / 2; i++) sub[i] = 0;
    for (int i = 0; i < n; i++) idx[i] = i;
    
    int maxWin = 0;
    do {
        A.clear(), B.clear();
        for (int i = 0; i < n; i++)
        {
            if (sub[i] == 0) A.emplace_back(idx[i]);
            else B.emplace_back(idx[i]);
        }
        cout << '\n';
        calcWin();
        
        int win = 0;        
        sort(aSum.begin(), aSum.end());
        sort(bSum.begin(), bSum.end());
        // for (auto a : aSum) cout << a << " ";
        // cout << '\n';
        // for (auto a : bSum) cout << a << " ";
        // cout << '\n';

        for (auto a : aSum)
        {
            // cout << lower_bound(bSum.begin(), bSum.end(), a) - bSum.begin() << '\n';
            win += lower_bound(bSum.begin(), bSum.end(), a) - bSum.begin();
        }
        
        // cout << "win : " << win << '\n';
        if (maxWin < win)
        {
            maxWin = win;
            for (int i = 0; i < n / 2; i++) answer[i] = A[i] + 1;
        }
        
    } while (next_permutation(sub, sub + n));


    
    return answer;
}