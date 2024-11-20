#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <thread>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
vector<pii> v;
int match[51];

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int val; cin >> val;
        v.emplace_back(val, i);
    }
}


void solution()
{
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < k; i++)
    {
        match[v[i].second] = v[i].second;
        cout << v[i].second << '\n';
    }
    for (int i = 1; i <= n; i++) cout << match[i] << '\n';

}

int main()
{
    INPUT();
    solution();
}