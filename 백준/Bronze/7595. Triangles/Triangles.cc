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
}

void solution()
{
    while (cin >> n)
    {
        if (!n) break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++) cout << "*";
            cout << '\n';
        }
    }
}

int main()
{
    INPUT();
    solution();
}