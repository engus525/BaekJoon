#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
int n, d, w;
priority_queue<pii> task;
bool day[1001]{false,};

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n;i++)
    {
        cin >> d >> w;
        task.push({w,d}); // {점수 , 마감일}
    }
}

void SOLVE()
{
    int ans = 0;

    while(!task.empty())
    {
        for(int i = task.top().second; i >= 1; i--)
        {// 가장 점수가 높은 과제를 최대한 미뤄서 해결한다.
            if(!day[i])
            {// 마감일부터 확인하다가 수행하지 않은 날을 발견한다면
                day[i] = true;
                ans += task.top().first;
                break;
            }
        }
        task.pop();
    }

    cout << ans;
}

int main()
{

    INPUT();
    SOLVE();
}
