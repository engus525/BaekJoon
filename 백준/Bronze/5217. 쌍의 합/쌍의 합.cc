#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t, n;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        cin >> n;
        cout << "Pairs for " << n << ": ";
        for (int i = 1; i < n - i; i++)
        {
            cout << i << " " << n - i;
            if (i + 1 < n - i - 1) cout << ", ";
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}