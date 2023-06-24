#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long ll;
ll a,b;
int n;
ll price[100005];
ll evenPs[100005];
ll oddPs[100005];
ll total = 0;
vector<pair<ll,ll>> range;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> price[i];
        total += price[i];
        if(i % 2) oddPs[i] = oddPs[max(0,i-2)] + price[i];
    }

}

ll setAns()
{
    ll ans = 0;
    sort(range.begin(), range.end());

    ll right = -1;
    for (auto &r : range)
    {
        if(right < r.first)
        {
            ans += r.second - r.first + 1;
            right = r.second;
        }
        else if(right < r.second)
        {
            ans += r.second - right;
            right = r.second;
        }
    }
    return ans;
}

void adjustRange(int idx, ll &left, ll &right)
{
    ll leftLine,rightLine;
    if(idx == 1)
    {
        leftLine = price[1];
        rightLine = 10e9;
    }
    else if(idx == n)
    {
        leftLine = 1;
        rightLine = price[n-1];
    }
    else
    {
        leftLine = price[idx];
        rightLine = price[idx-1];
    }

    left = max(leftLine, left);
    right = min(rightLine, right);
}

void SOLVE()
{
    for(int i = (n%2) ? n-1 : n-2; i >= 1; i-=2)
        evenPs[i] = evenPs[i+2] + price[i];

    for(int i = 1; i <= n; i++)
    {
        ll old, young;
        if(i % 2) old = oddPs[max(0,i-2)]+evenPs[i+1];
        else old = oddPs[i-1]+evenPs[i];
        young = total - old;

        ll gap = old - young;
        ll left,right;
        if(i % 2) left = a-gap, right = b-gap;
        else left = -(b-gap), right = -(a-gap);

        adjustRange(i,left,right);
        if(left > right) continue;

        range.emplace_back(left, right);
    }

    cout << setAns();
}

int main()
{
    INPUT();
    SOLVE();
}