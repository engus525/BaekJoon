#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
deque<int> dq;
bool have[1001], buy[1001];
int coin;
int n;
int target;
int ans = 0;

void printMyCards()
{
    cout << "\nHAVE : ";
    for (int i = 1; i <= n; i++)
        if (have[i]) cout << i << " ";
    cout << "\nBUY : ";
    for (int i = 1; i <= n; i++)
        if (buy[i]) cout << i << " ";
    cout << '\n';
}


int game()
{
    int ans = 1;
    while (!dq.empty())
    {
        
        buy[dq.front()] = true, dq.pop_front();
        buy[dq.front()] = true, dq.pop_front();
        
        bool pass = false;
        for (int i = 1; !pass && i <= n; i++)
        {
            // 코인 0개 소비
            if ((have[i] && have[target - i]))
            {
                // cout << "1 : "; printMyCards();
                have[i] = false, have[target - i] = false;
                pass = true;
                break;
            }
        }

        for (int i = 1; !pass && i <= n; i++)
        {
            // 코인 1개 소비
            if ((have[i] && buy[target - i]))
            {
                if (coin < 1) break;
                // cout << "2 : "; printMyCards();
                have[i] = false, buy[target - i] = false;
                pass = true;
                coin--;
                break;
            }
        }

        for (int i = 1; !pass && i <= n; i++)
        {
            // 코인 2개 소비
            if (buy[i] && buy[target - i])
            {
                if (coin < 2) break;
                // cout << "3 : "; printMyCards();
                buy[i] = false, buy[target - i] = false;
                pass = true;
                coin -= 2;
                break;
            }
        }
        
        if (!pass) break;
        ans++;
    }
    
    return min(n / 2, ans);
}

int solution(int coi, vector<int> v) {
    coin = coi;
    n = v.size();
    target = n + 1;
    for (int i = n / 3; i < v.size(); i++) dq.push_back(v[i]);
    for (int i = 0; i < n / 3; i++) have[v[i]] = true;
    
    
    return game();
}