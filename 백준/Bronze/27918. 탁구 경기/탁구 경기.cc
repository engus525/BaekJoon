#include <iostream>
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
    int x = 0, y = 0;
    while (t--)
    {
        char c;
        cin >> c;
        if (c == 'D') x++;
        else y++;

        if (x >= y + 2 || x + 2 <= y) break;
    }
    cout << x << ":" << y;
}

int main()
{
    INPUT();
    solution();
}