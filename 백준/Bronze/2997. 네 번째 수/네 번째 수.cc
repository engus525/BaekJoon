#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int num[3];

void INPUT()
{
    IAMFAST
    for (int &i : num) cin >> i;
}

void solution()
{
    sort(num, num + 3);
    int g1 = num[1] - num[0], g2 = num[2] - num[1];
    if (g1 == g2) cout << num[2] + g1;
    else if (g1 < g2) cout << num[1] + g2 / 2;
    else if (g1 > g2) cout << num[0] + g1 / 2;
}

int main()
{
    INPUT();
    solution();
}