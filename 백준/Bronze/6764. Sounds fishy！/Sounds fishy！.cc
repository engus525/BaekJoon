#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int d, a, b, c;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c >> d;
}

void solution()
{
    if (a < b && b < c && c < d) cout << "Fish Rising";
    else if (a > b && b > c && c > d) cout << "Fish Diving";
    else if (a == b && b == c && c == d) cout << "Fish At Constant Depth";
    else cout << "No Fish";
}

int main()
{
    INPUT();
    solution();
}