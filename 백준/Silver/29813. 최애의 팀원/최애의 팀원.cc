#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define BASE 1'000'005
#define MOD 1'000'000'000

int n;
deque<pair<string, int>> dq;

void INPUT()
{
    IAMFAST
    cin >> n;
    while (n--)
    {
        string str;
        int in;
        cin >> str >> in;
        dq.emplace_back(str, in);
    }
}

void solution()
{
    while (dq.size() > 1)
    {
        int cnt = (dq.front().second - 1) % (dq.size() - 1);
        dq.pop_front();
        while (cnt--)
        {
            dq.emplace_back(dq.front());
            dq.pop_front();
        }
        dq.pop_front();
    }
    cout << dq.front().first;
}

int main()
{
    INPUT();
    solution();
}