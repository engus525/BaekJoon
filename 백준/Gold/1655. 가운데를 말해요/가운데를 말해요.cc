#include <iostream>
#include <queue>
using namespace std;

int n;
int in;

priority_queue<int,vector<int>,greater<int>> minHeap;
priority_queue<int> maxHeap;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
}

void SOLVE()
{
    while(n--)
    {
        cin >> in;

        if(maxHeap.size() == minHeap.size())
        {
            if(!minHeap.empty() && (in > minHeap.top()))
                maxHeap.push(minHeap.top()),
                minHeap.pop(),
                minHeap.push(in);
            else
                maxHeap.push(in);
        }
        else if(maxHeap.size() == minHeap.size()+1)
        {
            if(!maxHeap.empty() && (in < maxHeap.top()))
                minHeap.push(maxHeap.top()),
                maxHeap.pop(),
                maxHeap.push(in);
            else
                minHeap.push(in);

        }

        cout << maxHeap.top() << '\n';
    }
}


int main()
{
    INPUT();
    SOLVE();
}