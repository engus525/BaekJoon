#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
int S[10001], D[10001];

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> S[i];
    for (int i = 1; i <= n; i++) cin >> D[i];
}


void solution()
{
    while (k--)
    {
        int temp[10001];
        for (int i = 1; i <= n; i++) temp[D[i]] = S[i];
        for (int i = 1; i <= n; i++) S[i] = temp[i];
    }
    for (int i = 1; i <= n; i++) cout << S[i] << " ";
}

int main()
{
    INPUT();
    solution();
}