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
int can = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int c; cin >> c;
        can += (c + 1) / 2;
    }
}


void solution()
{
    cout << ((can >= n) ? "YES" : "NO");
}

int main()
{
    INPUT();
    solution();
}