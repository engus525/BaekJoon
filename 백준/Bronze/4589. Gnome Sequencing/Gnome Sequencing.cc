#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t, a, b, c;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    cout << "Gnomes:\n";
    while (t--)
    {
        cin >> a >> b >> c;
        bool ans = false;
        if ((a < b && b < c) || (a > b && b > c)) ans = true;

        if (ans) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
}

int main()
{
    INPUT();
    solution();
}