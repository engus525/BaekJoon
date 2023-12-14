#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

priority_queue<pii> pq;
priority_queue<int, vector<int>, greater<int>> ans;

void INPUT()
{
    IAMFAST
    for (int i = 1; i <= 8; i++)
    {
        int score;
        cin >> score;
        pq.emplace(score,i);
    }
}


void solution()
{
    int sum = 0;
    while (pq.size() > 3)
    {
        sum += pq.top().first;
        ans.emplace(pq.top().second);
        pq.pop();
    }

    cout << sum << '\n';
    while (!ans.empty()) cout << ans.top() << " ", ans.pop();
}

int main()
{
    INPUT();
    solution();
}