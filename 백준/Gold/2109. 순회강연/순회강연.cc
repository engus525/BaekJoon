#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
typedef long long ll;
struct comp
{
    bool operator()(pair<int,ll> a, pair<int,ll> b)
    {
        if(a.second == b.second) return a.first > b.first;
        else return a.second < b.second;
    }
};
priority_queue<pair<int,ll>, vector<pair<int,ll>>, comp> pq;
bool visited[10001];
ll ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll p,d; cin >> p >> d;
        pq.emplace(d,p);
    }
}


void SOLVE()
{
    while(!pq.empty())
    {
        auto [d,p] = pq.top();
        for(int i = d; i >= 1; i--)
            if(!visited[i])
            {
                ans += p;
                visited[i] = true;
                break;
            }
        pq.pop();
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}