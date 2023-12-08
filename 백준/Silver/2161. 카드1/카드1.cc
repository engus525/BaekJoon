#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

deque<int> dq;
int n;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++) dq.emplace_back(i);
}


void solution()
{
    while (dq.size() > 1)
    {
        cout << dq.front() << " ";
        dq.pop_front();

        dq.emplace_back(dq.front());
        dq.pop_front();
    }
    cout << dq.front();
}

int main()
{
    INPUT();
    solution();
}