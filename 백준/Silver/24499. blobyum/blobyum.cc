#include <iostream>
#include <vector>
#include <queue>
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
typedef pair<long long, long long> pll;

int n,k;
int taste[100001];
int ps[200001];

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> taste[i];
        ps[i] = ps[i - 1] + taste[i];
    }
    for(int i = n + 1; i <= 2 * n; i++)
    {
        ps[i] = ps[i - 1] + taste[i - n];
    }
}


void solution()
{
    int ans = 0;
    for(int i = k; i <= 2 * n; i++)
    {
        if (i - k + 1 == n + 1) break;
        ans = max(ans, ps[i] - ps[i - k]);
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}