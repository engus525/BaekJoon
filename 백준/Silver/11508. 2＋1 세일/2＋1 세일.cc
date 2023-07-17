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
priority_queue<int> pq;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int c; cin >> c;
        pq.emplace(c);
    }
}


void solution()
{
    int ans = 0;
    int cnt = 0;
    while(!pq.empty())
    {
        if(cnt == 2) cnt = 0;
        else
        {
            ans += pq.top();
            cnt++;
        }
        pq.pop();
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}