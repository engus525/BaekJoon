#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

int n,h,t;
priority_queue<int> pq;

void INPUT()
{
    IAMFAST
    cin >> n >> h >> t;
    for(int i = 0; i < n; i++)
    {
        int tall; cin >> tall;
        pq.emplace(tall);
    }
}


void solution()
{
    int cnt;
    for(cnt = 0; cnt < t; cnt++)
    {
        //뿅망치로 때리기
        int top = pq.top();
        if(top == 1 || top < h) break;
        pq.pop();
        pq.emplace(top / 2);
    }

    if (pq.top() < h) cout << "YES\n" << cnt;
    else cout << "NO\n" << pq.top();
}

int main()
{
    INPUT();
    solution();
}