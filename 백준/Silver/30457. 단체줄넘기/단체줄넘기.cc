#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
priority_queue<int> pq;
vector<int> l, r;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        pq.emplace(num);
    }
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        if (pq.empty()) break;

        if (l.empty() || l.back() > pq.top())
        {
            l.emplace_back(pq.top()), pq.pop();
        }
        else if (r.empty() || r.back() > pq.top())
        {
            r.emplace_back(pq.top()), pq.pop();
        }
        else
        {
            pq.pop();
        }
    }

    cout << l.size() + r.size();
}

int main()
{
    INPUT();
    solution();
}