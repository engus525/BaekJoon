#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    int now = a - 60;
    while (now += 60)
    {
        if (now > b) break;
        cout << "All positions change in year " << now << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}