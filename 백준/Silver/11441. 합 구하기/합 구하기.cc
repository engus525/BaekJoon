#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, t;
int ps[100001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ps[i], ps[i] += ps[i - 1];
    cin >> t;
}


void solution()
{
    while (t--)
    {
        int s, e; cin >> s >> e;
        cout << ps[e] - ps[s - 1] << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}