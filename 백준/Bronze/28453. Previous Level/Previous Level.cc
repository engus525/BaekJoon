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
    while (n--)
    {
        int m; cin >> m;
        if (m >= 300) cout << 1 << " ";
        else if (m >= 275) cout << 2 << " ";
        else if (m >= 250) cout << 3 << " ";
        else cout << 4 << " ";
    }
}

int main()
{
    INPUT();
    solution();
}