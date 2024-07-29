#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
}

void solution()
{
    cout << ((n + m) % 12 == 0 ? 12 : (n + m) % 12);
}

int main()
{
    INPUT();
    solution();
}