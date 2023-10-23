#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <stack>
#include <cmath>
#include <set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    int ans = 0;
    while (n--)
    {
        int c, k;
        cin >> c >> k;
        ans += c * k;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}