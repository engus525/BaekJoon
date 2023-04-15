#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
typedef pair<int,int> pii;
vector<pii> v;
priority_queue<int,vector<int>,greater<int>> pq;//강의가 끝나는 시간

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int _ = 0; _ < n; _++)
    {
        int a,b; cin >> a >> b;
        v.emplace_back(a,b);
    }
}

void SOLVE()
{
    sort(v.begin(), v.end(),
         [](pii a, pii b)
         {
             if (a.first == b.first) return a.second < b.second;
             else return a.first < b.first;
         });

    pq.push(v[0].second);
    int ans = 1;
    for(int i = 1; i < v.size(); i++)
    {
        if(pq.top() <= v[i].first)
            pq.pop(), pq.push(v[i].second);
        else pq.push(v[i].second),ans++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}