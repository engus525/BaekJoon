#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
deque<pii> dq;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num; cin >> num;
        dq.emplace_back(i, num);
    }
}


void solution()
{
    auto [num, move] = dq.front();
    dq.pop_front();

    while(!dq.empty())
    {
        cout << num << " ";

        for (int i = 0; i < abs(move) - 1; i++)
        {
            if (move > 0) dq.push_back(dq.front()), dq.pop_front();
            else dq.push_front(dq.back()), dq.pop_back();
        }

        if (move > 0) num = dq.front().first, move = dq.front().second, dq.pop_front();
        else num = dq.back().first, move = dq.back().second, dq.pop_back();
    }
    cout << num;
}

int main()
{
    INPUT();
    solution();
}