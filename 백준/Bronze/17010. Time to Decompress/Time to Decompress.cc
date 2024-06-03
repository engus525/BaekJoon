#include <iostream>
#include <string>
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
    while (t--)
    {
        int a; char b;
        cin >> a >> b;
        for (int i = 0; i < a; i++) cout << b;
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}