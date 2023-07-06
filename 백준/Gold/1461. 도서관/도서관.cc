#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m;
vector<int> positive;
vector<int> negative;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int dist; cin >> dist;
        if(dist > 0) positive.emplace_back(dist);
        else negative.emplace_back(dist);
    }
}


void SOLVE()
{
    sort(positive.begin(),positive.end(),greater());
    sort(negative.begin(),negative.end());

    int right = 0;
    for(int i = 0; i < positive.size(); i += m)
        right += positive[i] * 2;
    int left = 0;
    for(int i = 0; i < negative.size(); i += m)
        left += abs(negative[i]) * 2;

    int ans = left + right;
    if(!positive.empty() && !negative.empty())
        ans -= max(positive[0],abs(negative[0]));
    else if(positive.empty()) ans -= abs(negative[0]);
    else if(negative.empty()) ans -= positive[0];

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}