#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
typedef long long ll;
int snow[601];
int ans = 2e9;
struct SNOW
{
    int x,y,sum;
};
bool comp(SNOW a,SNOW b)
{
    return a.sum < b.sum;
}
vector<SNOW> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> snow[i];
}


void SOLVE()
{
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            v.push_back({i, j, snow[i] + snow[j]});
    sort(v.begin(),v.end(),comp);


    for(int snow1 = 0; snow1 < v.size()-1; snow1++)
        for(int snow2 = snow1+1; snow2 < v.size(); snow2++)
        {
            if(v[snow1].x == v[snow2].x) continue;
            if(v[snow1].y == v[snow2].y) continue;
            if(v[snow1].y == v[snow2].x) continue;
            if(v[snow2].y == v[snow1].x) continue;

            ans = min(ans,v[snow2].sum-v[snow1].sum);
            break;
        }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}