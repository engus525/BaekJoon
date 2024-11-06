#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
priority_queue<pii, vector<pii>, greater<>> pq;
int overtimeCnt;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.emplace(a - 1, b);
    }
}


/**
 * Greedy
 * 마감 기한이 짧은 순으로 정렬한 뒤,
 * 최대한 평시 근무를 진행한 후 마감 기한 내에 끝내지 못한 경우 시간 외 근무 진행.
 * 
 * 이때 시간 외 근무를 진행한 수가 마감 기한을 넘어선다면, 작업 마무리 불가능
 * -> -1 출력
 */
void solution()
{
    int today = 0;
    while (!pq.empty())
    {
        auto [limit, need] = pq.top();
        pq.pop();

        while (need)
        {
            // 마감 기한 전까지 최대한 평시 근무 진행
            if (today > limit) break;
            // 평일일 때만 평시 근무 가능
            if (today % 7 < 5) need--;
            today++;
        }

        // 시간 외 근무 진행
        overtimeCnt += need;
        // 시간 외 근무 횟수가 마감 기한을 넘어선다면 -1 출력
        if (overtimeCnt > limit + 1)
        {
            cout << -1;
            return;
        }
    }

    cout << overtimeCnt;
}

int main()
{
    INPUT();
    solution();
}