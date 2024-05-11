#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        int a, b; cin >> a >> b;
        if (a >= b) cout << "MMM BRAINS\n";
        else cout << "NO BRAINS\n";
    }
}

int main()
{
    INPUT();
    solution();
}