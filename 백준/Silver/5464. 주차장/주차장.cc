#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int rs[101], wk[2001];
int parkedAt[2001];
int visited[101];
queue<int> q;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> rs[i];
    for (int i = 1; i <= m; i++) cin >> wk[i];
}

int findParkNum()
{
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            return i;
    return -1;
}

void calculateAns(int parkNum, int carNum)
{
    //cout << carNum << " parked at " << parkNum << '\n';
    ans += rs[parkNum] * wk[carNum];
}

void solution()
{
    for (int i = 0; i < 2 * m; i++)
    {
        int order;
        cin >> order;

        //출차
        if (order < 0)
        {
            order *= -1;
            visited[parkedAt[order]] = false;
            //출차 후 대기 차량 주차
            if (!q.empty())
            {
                int car = q.front();
                q.pop();

                parkedAt[car] = parkedAt[order];
                parkedAt[order] = 0;

                calculateAns(parkedAt[car], car);
                visited[parkedAt[car]] = true;
            }

            parkedAt[order] = 0;
            continue;
        }

        //주차 공간 찾기
        int num = findParkNum();

        //없다면 입구 대기
        if (num == -1) q.emplace(order);
        else
        {
            parkedAt[order] = num;

            calculateAns(num, order);
            visited[num] = true;
        }
    }

    cout << ans;
}


int main()
{
    INPUT();
    solution();
}