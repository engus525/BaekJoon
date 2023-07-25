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

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    int minFin = 2e9, maxStart = 0;
    for(int i = 0; i < n; i++)
    {
        int s, e; cin >> s >> e;
        maxStart = max(maxStart, s);
        minFin = min(minFin, e);
    }

    int ans = 0;
    if (minFin < maxStart) ans = maxStart - minFin;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}