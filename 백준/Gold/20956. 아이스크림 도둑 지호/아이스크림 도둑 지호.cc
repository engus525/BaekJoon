#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int A;

typedef pair<int,int> pii;
struct comp
{
    bool operator()(pii a,pii b)
    {
        if(a.first == b.first) return a.second > b.second;//오름차순
        else return a.first < b.first;//내림차순
    }
};
priority_queue<pii,vector<pii>,comp> minHeap;//작은 인덱스가 먼저
priority_queue<pii> maxHeap;//큰 인덱스가 먼저
bool visited[100001];
bool isReversed = false;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> A;
        minHeap.push({A,i});
        maxHeap.push({A,i});
    }
}


void SOLVE()
{
    while(m--)
    {
        if(isReversed)
        {
            while(visited[maxHeap.top().second]) maxHeap.pop();
            if(maxHeap.top().first % 7 == 0) isReversed = !isReversed;
            cout << maxHeap.top().second << '\n';
            visited[maxHeap.top().second] = true;
            maxHeap.pop();
        }
        else
        {
            while(visited[minHeap.top().second]) minHeap.pop();
            if(minHeap.top().first % 7 == 0) isReversed = !isReversed;
            cout << minHeap.top().second << '\n';
            visited[minHeap.top().second] = true;
            minHeap.pop();
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}