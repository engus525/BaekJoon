#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t, a;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{

    while (t--)
    {
        cin >> a;
        for (int i = 0; i < a; i++) cout << "=";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}