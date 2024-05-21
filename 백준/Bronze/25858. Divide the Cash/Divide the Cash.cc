#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int member[31];
int total = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> member[i], total += member[i];
}

void solution()
{
    for (int i = 0; i < n; i++) cout << member[i] * m / total << '\n';
}

int main()
{
    INPUT();
    solution();
}