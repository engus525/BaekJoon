#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c;

void INPUT()
{
    IAMFAST
}

void solution()
{
    while (cin >> a >> b >> c)
    {
        if (!a && !b && !c) break;

        if (b - a == c - b) cout << "AP " << c + (b - a);
        else cout << "GP " << c * (b / a);
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}