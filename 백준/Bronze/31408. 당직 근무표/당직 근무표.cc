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

int n;
int cnt[100001];
int maxCnt = 0, maxIdx = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val; cin >> val;
        cnt[val]++;
        if (maxCnt < cnt[val])
        {
            maxCnt = cnt[val];
            maxIdx = val;
        }
    }
}


void solution()
{
    if ((n % 2) ? (maxCnt <= (n + 1) / 2) : (maxCnt <= n / 2)) cout << "YES";
    else cout << "NO";
}

int main()
{
    INPUT();
    solution();
}