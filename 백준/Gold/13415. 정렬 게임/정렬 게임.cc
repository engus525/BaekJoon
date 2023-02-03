#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int list[100001];
int k,a,b;

deque<pair<int,int>> dq;
int ans[100001];
int maxRange;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> list[i];
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> a;
        while(!dq.empty() && dq.back().first <= a) dq.pop_back();
        dq.push_back({a,1});

        cin >> b;
        while(!dq.empty() && dq.back().first <= b) dq.pop_back();
        dq.push_back({b,-1});
    }
}

int Range()
{
    int endPoint = dq.front().first;
    dq.pop_front();
    int startPoint;
    if(dq.empty()) startPoint = 0;
    else startPoint = dq.front().first;

    return endPoint - startPoint;
}

void SOLVE()
{
    maxRange = dq.front().first;//정렬될 구간의 길이

    sort(list+1,list+1+maxRange);

    int left = 1 , right = maxRange , idx = maxRange;
    while(!dq.empty())
    {

        int option = dq.front().second;
        int range = Range();

        for(int i = 0; i < range; i++)
        {
            if(option == 1)
            {
                ans[idx] = list[right];
                right--;
                idx--;
            }
            else
            {
                ans[idx] = list[left];
                left++;
                idx--;
            }
        }
    }

    for(int i = 1; i <= maxRange; i++) cout << ans[i] << " ";
    //정렬되지 않은 부분 출력
    for(int i = maxRange+1; i <= n; i++) cout << list[i] << " ";
}


int main()
{
    INPUT();
    SOLVE();
}