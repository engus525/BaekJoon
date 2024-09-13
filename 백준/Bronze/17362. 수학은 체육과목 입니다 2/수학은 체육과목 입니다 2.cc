#include <iostream>
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
    int now = 1;
    while (now + 8 < n) now += 8;

    int gap = n - now;
    if (gap % 8 == 0) cout << 1;
    else if (gap == 1 || gap == 7) cout << 2;
    else if (gap == 2 || gap == 6) cout << 3;
    else if (gap == 3 || gap == 5) cout << 4;
    else if (gap == 4) cout << 5;
}

int main()
{
    INPUT();
    solution();
}