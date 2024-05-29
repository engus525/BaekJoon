#include <iostream>
#include <string>
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
    for (int i = 1; i <= n; i++)
    {
        if (i % 7 == 0 && i % 11 == 0) cout << "Wiwat!\n";
        else if (i % 7 == 0) cout << "Hurra!\n";
        else if (i % 11 == 0) cout << "Super!\n";
        else cout << i << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}