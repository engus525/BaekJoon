#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

ll sum1 = 0, sum2 = 0;
queue<ll> q1, q2;

void getSum(vector<int> v1, vector<int> v2)
{
    for (int i = 0; i < v1.size(); i++)
        sum1 += v1[i], q1.emplace(v1[i]), sum2 += v2[i], q2.emplace(v2[i]);
}

int solution(vector<int> v1, vector<int> v2) {
    int answer = 0;
    
    getSum(v1, v2);
    
    while (sum1 != sum2)
    {
        if (answer == 2 * v1.size() + 2)
        {
            answer = -1;
            break;
        }
        answer++;
        
        if (sum1 > sum2)
        {
            sum1 -= q1.front();
            sum2 += q1.front();
            q2.emplace(q1.front());
            q1.pop();
        }
        else
        {
            sum2 -= q2.front();
            sum1 += q2.front();
            q1.emplace(q2.front());
            q2.pop();
        }
    }
    
    return answer;
}