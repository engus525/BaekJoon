#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int val[1000002];
int ps[1000002];
int minV = 2e9;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        ps[i] = ps[i - 1] + val[i];
        if (i >= 2) minV = min(minV, ps[i] - ps[i - 2]);
    }
}

void solution()
{
    cout << m * minV;
}

int main()
{
    INPUT();
    solution();
}