#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
#define IAMFAST                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}


void solution()
{
    if (a >= 3 && b <= 4) cout << "TroyMartian\n";
    if (a <= 6 && b >= 2) cout << "VladSaturnian\n";
    if (a <= 2 && b <= 3) cout << "GraemeMercurian\n";
}

int main()
{
    INPUT();
    solution();
}
