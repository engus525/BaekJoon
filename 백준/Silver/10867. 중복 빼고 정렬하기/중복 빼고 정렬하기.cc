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
typedef pair<ll, ll> pll;

int n;
bool visited1[1001];
bool visited2[1001];
vector<int> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        if(num >= 0 && visited1[num]) continue;
        if(num < 0 && visited2[-num]) continue;
        
        if(num >= 0) visited1[num] = true;
        if(num < 0) visited2[-num] = true;
        v.emplace_back(num);
    }
}

void solution()
{
    sort(v.begin(), v.end());
    for(auto &i : v) cout << i << " ";
}

int main()
{
    INPUT();
    solution();
}