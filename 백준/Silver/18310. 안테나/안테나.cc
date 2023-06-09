#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
vector<int> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int dist; cin >> dist;
        v.emplace_back(dist);
    }
}

void SOLVE()
{
    sort(v.begin(), v.end());
    int idx = (v.size() % 2) ? v.size()/2 : v.size()/2 - 1;
    cout << v[idx];

}

int main()
{
    INPUT();
    SOLVE();
}