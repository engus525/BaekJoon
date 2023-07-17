#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n;
deque<int> dq;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++) dq.emplace_back(i);
}


void solution()
{
    for(ll i = 1; dq.size() != 1; i++)
    {
        ll moveCnt = (i*i*i-1) % ll(dq.size());
        for(int j = 0; j < moveCnt; j++)
        {
            dq.emplace_back(dq.front());
            dq.pop_front();
        }
        dq.pop_front();
    }
    cout << dq.front();
}

int main()
{
    INPUT();
    solution();
}