#include <iostream>
#include <math.h>
#include <algorithm>

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
    for (int i = 1; i <= n; i++)
    {
        if (i % 6 == 0 || i == n) cout << i << " Go! ";
        else cout << i << " ";
    }
}

int main()
{
    INPUT();
    solution();
}